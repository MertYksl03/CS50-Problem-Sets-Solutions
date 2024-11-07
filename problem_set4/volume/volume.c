// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef int8_t BYTE;

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
    BYTE temp;
    int count = 0;

    //read the input file and write the output file
    while (fread(&temp , sizeof(temp) , 1 , input))
    {
        if(count <= 44)
        {
            fwrite(&temp , sizeof(temp) , 1 , output);
        }
        else 
        {
            temp*=factor;
            fwrite(&temp, sizeof(temp), 1 , output);
        }
        count++;
    }
    // Close files
    fclose(input);
    fclose(output);
}
