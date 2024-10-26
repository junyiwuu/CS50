#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define blocksize 512

int main(int argc, char *argv[])
{
    //check command line
    if(argc != 2)
    {
        printf("Usage ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    //check if the file open correctly
    if (card == NULL)
    {
        printf("file not open correctly");
        return 1;
    }

    uint8_t buffer[blocksize];
    FILE *output_file = NULL;
    int file_count = 0;
    char filename[8];

    while (fread(buffer, sizeof(char), blocksize, card) == blocksize)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //close previous file
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            sprintf (filename, "%03i.jpg", file_count);
            output_file = fopen(filename , "w");

            //if nothing inside
            if (output_file == NULL)
            {
                printf("nothing inside");
                fclose(card);
                return 1;
            }
            file_count++;
        }

        //write the file
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), blocksize, output_file);
        }
    }
    //finish while, reach the end
    if (output_file != NULL)
    {
        fclose (output_file);
    }
    fclose(card);

    return 0;
}
