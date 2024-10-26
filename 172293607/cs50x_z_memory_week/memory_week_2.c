#include <stdio.h>


void swap(int *a, int *b);

int main(void)
{
    int x = 3;
    int y = 1;

    printf("WAS: x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("NOW: x is %i, y is %i\n", x, y);

}

// need to use pointer to change the address
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}



//c language version of get integer
int main(void)
{
    int n;
    printf("n: ");
    scanf("%i", &n); //get the integer, and give to address n
    printf("n: %i\n", n);
}



//----------------------
//basically is get_string function from cs50
#include <stdlib.h>
int main(void)
{

    //char *s; //string is just a address of the first byte
    //so we only need to store the first char address

    //it si uninitialized, which mean it as a pointer, will point to random place

    char *s = malloc(2*sizeof(char));
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
    free(s);

//---------------------

//basically is get_string function from cs50
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
   // free(s);
}
//----------------------


#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");

    //check if the file address exist
    if(!file)
    {
        return 1;
    }

    char *name = get_string("name: ");
    char *number = get_string("number: ");

    fprintf(file, "%s, %s\n", name, number);


    fclose(file);
}




//give me an eight bit value that is unsigned (no negative)
//BYTE is the nickname/ alias of uint8_t this data type.. this line means a data type
typedef uint8_t BYTE;

int main( int argc, char *argv[])
{
    //is a pointer to that file in memory
    //open a file and turning the address of the file
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    //r open text file
    //rb open non-test file

    BYTE b;
    //printf("%i\n", b);  unintialized, cant print

    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }
    fclose(dst);
    fclose(src);
}





int main()
{
    FILE *fp;
    char c[] = "this is tutorialpoint";
    char buffer[100];

    fp = fopen("file.txt", "w+");
    fwrite(c, strlen(c)+1, 1, fp);
    fseek(fp, 0, SEEK_SET);

    fread(buffer, strlen(c)+1, 1, fp);
    //fread(*pointers, )

    printf("%s\n", buffer)

}
