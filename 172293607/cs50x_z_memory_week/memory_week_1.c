#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//-----------------------------------
int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
}

//-----------------------------------

int main(void)
{
    char *s = "HI!";
    printf("%c", *s);
    printf("%c", *(s + 1));
    printf("%c\n", *(s + 2) );
}

//-----------------------------------

//compare different strings
int main(void)
{
    char *a = get_string("input1: ");
    char *b = get_string("input2: ");

    printf("%p\n",a);
    printf("%p\n",b);
}


//-----------------------------------

int main(void)
{
    char *s = get_string("input: ");
    char *t = malloc(strlen(s + 1)); //memory allocate, and allocate how many bytes
    //one letter is one byte, here dynamically figure out how many bytes need
    //add one in the end for \0
    for( int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s, %p\n", s, s);
    printf("%s, %p\n", t, t);
}

//-----------------------------------

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);
}

//-----------------------------------

int main(void)
{
    int sem[10];
    for( int i = 0; i<10; i++)
    {
        printf("%i\n", sem[i]);
    }
}
