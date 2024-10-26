#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    for (int j = 0; j < n; j++)
    {

        for (int i = n; i > j + 1; i--)
        {
            printf(" ");
        }

        for (int i = 0; i <= j; i++)
        {
            printf("#");
        }

        printf("  ");

        for (int i = 0; i <= j; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}
