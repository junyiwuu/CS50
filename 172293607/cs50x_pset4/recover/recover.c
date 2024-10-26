#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

#define blocksize 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usange ./recover FILE\n");
        return 1;
    }

    //open memory card
    FILE *fp = fopen (argv[1], "r");

    if ( fp == NULL)
    {
        perror ("file not open properly");
        exit(1);
    }

    //temporarliy store data in buffer when reading data from file
    //buffer -- 512 bytes -- store data blocks
    BYTE buffer[blocksize];
    FILE *output_file = NULL;
    int file_num = 0;
    char filename[8];

    while (fread(buffer, 1, blocksize, fp) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 )
        {
            //close previous file if exist
            if(output_file != NULL)
            {
                fclose(output_file);
            }

            //sprintf not print to terminal, but print as a string
            sprintf(filename, "%03i.jpg", file_num);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                perror(" could not create output file");
                fclose(fp);
                return 1;
            }
            file_num ++ ;
        }

        if(output_file != NULL)
        {
            fwrite(buffer, 1, blocksize, output_file);
        }
    }

    if (output_file != NULL)
    {
        fclose(output_file);
    }
    fclose(fp);

    return 0;
    

}
