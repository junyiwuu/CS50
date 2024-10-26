#include <cs50.h>
#include <math.h>
#include <stdio.h>

// calculate the length of input number
int get_length(long num)
{
    int len = 0;
    // it is forever go to integer
    if (num == 0)
    {
        return 1;
    }
    while (num != 0)
    {
        num /= 10;
        len++;
    }
    return len;
}

// find the digit function
int find_digit(long input_numbers, int index)
{
    //int n = get_length(input_numbers);
    int digit;
    long div = pow(10, index);
    digit = (input_numbers / div) % 10;

    return digit;
}

int main(void)
{
    long num = get_long("Number: ");
    int n = get_length(num);
    long sum_multi = 0;
    long sum_single = 0;

    // start from the second last.  ; i <= n ; i++
    for (int i = 1; i <= n; i = i + 2)
    {
        int digit = find_digit(num, i) * 2;
        sum_multi += digit / 10 + digit % 10;
    }

    for (int i = 0; i <= n; i = i + 2)
    {
        int digit = find_digit(num, i);
        sum_single += digit;
    }

    int overall = sum_multi + sum_single;

    if (overall % 10 == 0)
    {
        int first_two = num / (long) pow(10, n - 2);
        int first_one = num / (long) pow(10, n - 1);
        if ((first_two >= 51 && first_two <= 55) && (n == 16))
        {
            printf("MASTERCARD\n");
        }
        else if ((first_two == 34 || first_two == 37) && (n == 15))
        {
            printf("AMEX\n");
        }
        else if ((first_one == 4) && (n == 13 || n == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

/*
//get the last number, or second last number
int main(void)
{
    int a = get_long("number: ");
    int b = a/10;
    printf("%i\n", b%10);
}
*/
