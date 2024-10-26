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
    //first it only copy the first 44 bytes
    //how header and content seperate is because of different data type
    uint8_t header[HEADER_SIZE];

    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    //after fread the header, it already go to the position where finish the header and start the content
    int16_t buffer;
    // allocate memory for buffer
    // the data range is -32768 to 32768
    // only install one, a 2 bytes(16 bits ) integer

    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *=
            factor; // keep overwrite the buffer, because buffer only write one number every time
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
