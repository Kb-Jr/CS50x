#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
// prompt user for text, declare variables for number or words, sentences and letters and initialize to 0
    string s = get_string("text: ");
    int number_words;
    int number_sentences;
    int number_letters;

    number_words = 0;

    number_sentences = 0;

    number_letters = 0;


    for (int i = 0; i < strlen(s); i++)
// determine letters by checking if its an alphabet and increase letter count by 1 for every letter detected
    {
        if (isalpha(s[i]))
        {
            number_letters++;
        }
// determine words by checking for blank spaces. characters after blank spaces indicate the begining of a new word, hence word count will be increased by 1

        if ((i == 0 && s[i] != ' ') || (i != strlen(s) - 1 && s[i] == ' ' && s[i + 1] != ' '))

        {
            number_words++;
        }

// determine what are sentences by using ". ! and ?" as indicators of end of sentences. When a sentence is detected increment the sentence count by 1
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')

        {
            number_sentences++;
        }

    }

// solve for L, S and index respectively and ensure to cast the denominators and round the result of index to a whole number
    float L = (number_letters / (float)number_words) * 100;
    float S = (number_sentences / (float)number_words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);


// if the result of index is less than 1 print Before grade 1, if greater than 16 print Grade 16+ anything else, the integer value of index should be printed alongside "grade"
    if (index <= 1)

    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)

    {
        printf("Grade 16+\n");
    }

    else

    {
        printf("Grade %i\n", index);
    }

}