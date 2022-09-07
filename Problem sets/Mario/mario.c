#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }

    // expression to prompt user to imput figure between 1 and 8

    while
    (h < 1 || h > 8);

    // Nested loop

    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < h; col++)
        {
            if (row + col < h - 1)
            printf(" ");
            else
            printf("#");
    // condition: if the sum of the row and column is less than the specified height minus 1 print space other wise print #. Using a grid approach
        }
        printf("\n");
    }
    //Print the corresponding pyramid
}
