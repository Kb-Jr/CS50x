#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool check_valid_key(string s);


int main(int argc, string argv[])

{
    if (argc != 2 || !check_valid_key(argv[1]))
    {
        printf("usage: ./caesar key\n");
        return 1;
    }
    // Reject argument count which is not equal to 2 or argument vector that is not a valid key

    int key = atoi(argv[1]);
    // Define Key, convert ASCII to integer

    string plaintext = get_string("plaintext: ");
    // get plaintext input from user

    printf("ciphertext: ");
    //printf the ciphertext

    for (int i = 0, len = strlen(plaintext); i < len; i++)
        // iterate over the plaintext

    {
        char c = plaintext [i];
        if (isalpha(c))
            // check if character c is alphabet

        {
            char x = 'A';
            // where x is the modifying character

            if (islower(c))

                x = 'a';

            // if character is lower case convert to lower case

            printf("%c", (c - x + key) % 26 + x);
            // apply formula given (ci = (pi + k) % 26)

        }
        else

        printf ("%c", c);

    }

    printf("\n");
}


bool check_valid_key(string s)
{

    for (int i = 0, len = strlen(s); i < len; i++)
        if (!isdigit(s[i]))
        return false;
        return true;
        // if not a digit return false, otherwise return True


        //code snippet from @thebestcodetutor
}