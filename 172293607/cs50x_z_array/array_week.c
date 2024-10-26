#include <stdio.h>
#include <cs50.h>
#include <string.h>

#include <ctype.h>
/*
const int N = 3;

int main(void){
    int score[N];
    int sum=0;
    for(int i=0 ; i < N ; i++ )
    {
        score[i] = get_int("score: ");
        sum += score[i];
    }
    printf("averagge : %d\n ", sum/N);
}
*/

/*
const int N = 3;
int main(void)
{

    char c[N];
    for(int i =0; i<N ; i++)
    {
        c[i]= get_char("input: ");

    }
    printf("%i%i%i\n" , c[0], c[1], c[2]);
}
*/

/*
int main(void)
{
    string os = "hi!";
    printf("%i%i%i%i\n", os[0], os[1], os[2]);
}
*/

/*
int string_len(string s)
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
   return n;
}


int main(void)
{
    string s = get_string("Input: ");
}
*/

/*
int main(void)
{
    string s = get_string("input: ");
    printf("output: ");

    for( int i = 0 ; i<strlen(s) ; i++ )
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
*/

/*
//manual way to uppercase the input
int main(void)
{
    string s = get_string("input: ");
    printf("output: " );

    int n = strlen(s);
    for( int i = 0 ; i<n ; i++)
    {
        //check if it is lowercase
        if( s[i] >= 'a' && s[i] <= 'z' )
        {
            printf("%c" , s[i]- ('a' - 'A' ) );
        }
        //check if it is not lowercase
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
*/


/*
//using <ctype.h> toupper
int main(void)
{
    string s = get_string("input: ");
    printf("output: ");
    int n = strlen(s);
    for(int i=0 ; i<n ; i++ )
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
*/

/*
int main(int argc, string argv[])
{
    printf("hello, %s \n", argv[1]);
}
*/

int main(int argc, string argv[])
{
    for (int i = 1 ; i < argc; i++ )
    {
        printf("argv[%d]: %s \n", i , argv[i]);
    }
}

