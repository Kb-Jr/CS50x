#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
        {
            if (strcmp (name, candidates [i].name) == 0)
            {
                preferences [voter][rank] = i;
                return true;
            }
        }
    return false;
// iterate through candidate_count, check if the name of candidate is similar to the voters choice by using strcmp and update preferences to the voter rank preferences, rerurn true.
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    int candidate;

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
            {
                candidate = preferences [i][j];
                if (!candidates[candidate].eliminated)
                    {
                        candidates[candidate].votes++;
                        break;
                    }
            }
    }
//iterate through voter_count and candidate_count, assign preferences to variable "candidate", check if the particular candidate preference has been eliminated and update votes if true
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int votes_major = round (voter_count / 2);
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > votes_major)
            {
                printf("%s\n", candidates[i].name);
                return true;
            }
    }
    return false;
//assign the value of half the voter count to votes_major, iterate through candidate_count and check if the candidate_vote is greater than votes_major and print the candidate_name at that index
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int minimum_votes = candidates [0].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < minimum_votes)
            {
                minimum_votes = candidates[i].votes;
            }
    }
    return minimum_votes;

// assign the 1st candidate votes to minimum votes, iterate through candidate_count and then check to see if any candidate has less than the minimum_votes then update the minimum votes
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
            {
                return false;

            }
    }
    return true;
// iterate throuh candidate_count, check if eliminated candidates and votes are not equal to min and return false if thats the case
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
// iterate through candidate_count, check if candidate_vote = min and set candidate_eliminated to true
}


// Credit:ideas and guide from Collins @collinsnote.com