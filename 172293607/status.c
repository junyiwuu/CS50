#include <cs50.h>
#include <stdio.h>

int main( int argc, string argv[])
{
    if(argc != 2)
    {
        printf("wrong\n");
        return 101;
    }
    else
    {
        printf("hey, %s\n", argv[1]);
    }
}
