#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string s)
{
    int count = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string s)
{
    int count = 1;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string s)
{
    int count = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int main(void)
{
    string s = get_string("input: ");

    int words = count_words(s);
    int letters = count_letters(s);
    int sentences = count_sentences(s);

    double L = (double) letters / words * 100;
    double S = (double) sentences / words * 100;

    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
