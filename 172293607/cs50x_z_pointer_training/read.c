#include <stdio.h>

int main(void)
{
    FILE *fp;
    int c;

    fp = fopen("file.txt", "r");

    //while(1) means loop forever until break
    while(1)
    {
        //getc gets the nect char(unsigned) from thr
        //specific stream and advance the position indicator
        //for the stream
        c = fgetc(fp);
        if(feof(fp))
        {
            break;
        }
        printf("%c", c);
    }
    fclose(fp);
    return 0;
}
