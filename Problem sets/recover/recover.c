#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
// size of a FAT file system

typedef uint8_t BYTE;
// define an 8 bit variable: "BYTE"


void checkArgumentCount(int argc);
void checkFileExists(FILE *file);
int isJPEG(BYTE buffer[]);


int main(int argc, char *argv[])
{
    checkArgumentCount(argc);
    FILE *row = fopen(argv[1], "r");
    checkFileExists(row);
//open the file in read mode and confirm file exists

    BYTE buffer[BLOCK_SIZE];
//create an array of bytes Block_size which is 512 bytes as earlier declared. This allocates neccesary memory

    char filename[8];
    FILE *image;
    int counter = 0;
// Buffer for filename, initialize counter to zero. Counter keeps track of what jpeg is being written to

    while (fread(buffer, BLOCK_SIZE, 1, row) == 1)
    {

        if (isJPEG(buffer) == 1)
//close the image given its not the first image
        {
            if (counter != 0)
            {
                fclose(image);
            }

            sprintf(filename, "%03i.jpg", counter++);
            image = fopen(filename, "w");
            fwrite(buffer, BLOCK_SIZE, 1, image);

//Print the name of the file, write file name to "image"
        }

        else if (counter > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }
    }
}
void checkArgumentCount(int argc)
{
    if (argc != 2)
    {
        printf("usage: ./recover image\n");
        exit(1);
    }
}
//check if the argument count is accurate, else exit
void checkFileExists(FILE *file)
{
    if (file == NULL)
    {
        printf("file could not be opened \n");
        exit(1);
    }

}


int isJPEG(BYTE buffer [])

{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
//checking for a jpeg header
    {
        return 1;
    }
    return 0;
}


//Credit: @Dors coding school, @https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm