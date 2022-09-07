// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    typedef uint8_t BYTE;
    typedef int16_t New_audio;
    // Define "Byte" as 8 bit type is not available in C, and define the new sample Audio which is 16 bits or 2 bytes

    BYTE headerBuffer [HEADER_SIZE];
    // create an array of Byte of the header_size i.e 44; headerbuffer

    fread(headerBuffer, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(headerBuffer, sizeof(BYTE), HEADER_SIZE, output);
    // reading the array, the size of Byte (8 bits), header size (44) and finally the input, then writing it to the output


    // TODO: Read samples from input file and write updated data to output file
    New_audio buffer;
    //16 bits new audio

    while (fread(&buffer, sizeof(New_audio), 1, input) == 1)
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(New_audio), 1, output);

    }
    //Keep reading from raw file until the end.
    //read the address of the array, size of new_audio (16 bits) as input
    //multiply the variable "buffer" by the factor and write to the output

    // Close files
    fclose(input);
    fclose(output);
}


//credit: @https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm
