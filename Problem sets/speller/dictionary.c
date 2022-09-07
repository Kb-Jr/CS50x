// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 5381;

// Hash table
node *table[N];

// Initialize Dictionary words and hashcode to keep track of the number words added to the dictionary

unsigned int dictwords = 0;

unsigned int hashcode = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
// hash word to obtain hash code
    hashcode = hash(word);
    node *cursor = table[hashcode];

//as long as "cursor" is not pointing to a Null node,loop through the linked list comparing words case insesitively until the word in question is found, if not found return false
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number

//Source: djb2 hash function from http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(const char *word)
{
    // TODO
    unsigned long hash = 5381;
    int c;

    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c;
        //hash * 33 + c

    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
//open dictionary file in read mode
    FILE *filepointer = fopen(dictionary, "r");

//given filepointer is not Null, read strings from file until end of file
    if (filepointer != NULL)
    {
        while (fscanf(filepointer, "%s", word) != EOF)
        {
//allocate memory for a new node
            node *n = malloc(sizeof(node));

            {
                hashcode = hash(word);
//copy word into the node, insert the node into one of the linked lists in the hash table
                strcpy(n->word, word);
                n->next = table[hashcode];
                table[hashcode] = n;


                dictwords++;
            }
        }
        fclose(filepointer);
    }
    else
    {
        return false;
    }

    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    return dictwords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {

        node *cursor = table[i];
//create a new variable 'tmp' and let it be equal to cursor, move cursor to the next element of the linked list before freeing tmp and repeat until cursor points to Null
        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);

        }


        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }

    }
    return false;
}

//Credits: snippets from @mayconpm @github.com, hash function from http://www.cse.yorku.ca/~oz/hash.html