#include <stdio.h>
#include <string.h>
int main(void)
{
    FILE *fp;
    fp = fopen("file.txt", "w+");
    fprintf(fp, "%s %s %s %d\n" , "we", "are", "in", 1882);

    fclose(fp);
    return 0;

}
