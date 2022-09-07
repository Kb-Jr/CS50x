#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    // To propmpt user for input of change owed

    while (change <= 0);
    // To ensure input is not less than 0 i.e a negative value

    int cent = round(change * 100);
    // convert cent to dollar and round up to avoid excess values

    int count = 0;
    // Declare new integer "count" to count the number of times a coin will be used to get to the change owed

    while (cent >= 25)
    {
        cent = cent - 25;
        count++;

    }
     //While loop and subtraction to divide the change by the coins (change owed - 25) then count the number of times the coin was used; repeat for the different coin denominations
    //#code snippet from @Consxious @youtube
    while (cent >= 10)
    {
        cent = cent - 10;
        count++;

    }
    //change owed - 25 - 10

    while (cent >= 5)
    {
        cent = cent - 5;
        count++;

    }
    //change owed - 25 -10 -5

    while (cent >= 1)
    {
        cent = cent - 1;
        count++;

    }
    // change owed - 25 - 10 -5 -1

    printf("%i\n", count);
    // print the number of coins used by using the count
}