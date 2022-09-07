#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
//iterate through the height and width with variables i and j respectively
        {
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            int average = round((Red + Green + Blue) / 3);

            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
// convert each of the rgbt values to float, derive the average and then update each rgbt value to the new average
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
//iterate through the height and width with variables i and j respectively

        {
            float floatRed = image[i][j].rgbtRed;
            float floatGreen = image[i][j].rgbtGreen;
            float floatBlue = image[i][j].rgbtBlue;

//convert each of the original rgbt values to float

            int sepiaRed = round(.393 * floatRed + .769 * floatGreen + .189 * floatBlue);
            int sepiaGreen = round(.349 * floatRed + .686 * floatGreen + .168 * floatBlue);
            int sepiaBlue = round(.272 * floatRed + .534 * floatGreen + .131 * floatBlue);

//Apply the sepia algorithm provided

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
//cap the result of sepiaRed, green or blue at 255

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    //update the value of the pixels

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)

//iterate through the height and width with variables i and j respectively; in this case the entire width will not be iterated through, it only goes halfway through

        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }

//create a temporary file called "temp" to store the first pixels, then move the last pixels to the vacated space, then insert the value of temp into the last positions
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

//create a temporary copy of image to store new pixel values as the loop executes


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
//iterate through the height and width with variables i and j respectively

        {
            int totalRed, totalGreen, totalBlue;
            totalRed = totalGreen = totalBlue = 0;
            float counter = 0.00;
//get the average, initialize it all to zero, anytime an edge is encountered the counter will be incremented


            for (int x = -1; x < 2; x++)

            {
                for (int y = -1; y < 2; y++)
//Declare two new variables x and y, -1 represents the position of the pixel before the pixel at the edge

                {
                    if (i + x < 0 || i + x > height - 1 || j + y < 0 || j + y > width - 1)

                    {
                        continue;
//If any of the above conditions occur ignore the for loop and continue, else proceed below
                    }

                    totalRed += image[i + x][j + y].rgbtRed;
                    totalGreen += image[i + x][j + y].rgbtGreen;
                    totalBlue += image[i + x][j + y].rgbtBlue;

                    counter++;
//Sum up everything for red, green and blue, i.e the sums of all the reds in the the surrounding pixels, same for green and blue then record the number of pixels counted around it
                }

            }

            temp[i][j].rgbtRed = round(totalRed / counter);
            temp[i][j].rgbtGreen = round(totalGreen / counter);
            temp[i][j].rgbtBlue = round(totalBlue / counter);
//round the value gotten from the total divided by the count recorded by the counter and assign to the temp image
        }

        for (i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)

            {
                image[i][j].rgbtRed = temp[i][j].rgbtRed;
                image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
                image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            }
// loop through the height and width and update the values of the original (image [i][j]) to the temp values (temp [i][j]) which are basically the average of surrounding pixels assigned to individual pixels
        }
        return;
    }

}


//Credit: @ndiecodes @github, @anvea @youtube
