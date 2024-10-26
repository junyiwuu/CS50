#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool check_duplicate(string s);

int main(int argc, string argv[])
{

    string key = argv[1];

    //filter errors
    if(argc != 2)
    {
        printf("Usage : %s key\n", argv[0] );
        return 1;
    }

    if(strlen(argv[1])!=26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if(check_duplicate(key))
    {
         return 1;
    }


    for (int i = 0; i < 26; i++ )
    {
        if(!isalpha(key[i]))
        {
            return 1;
        }
    }

    //start main
    string plain = get_string("plaintext: ");
    int n = strlen(plain);
    //create cipher array
    char cipher[n+1];

    for (int i = 0 ; i < n; i++ )
    {

        if (isupper(plain[i]))
        {
            int index = plain[i] - 'A';
            cipher[i] = toupper(key[index]);
        }
        else if (islower(plain[i]))
        {
            int index = plain[i] - 'a';
            cipher[i] = tolower(key[index]);
        }
        else
        {
            cipher[i] = plain[i];
        }
    }

    cipher[n] = '\0';
    printf ("ciphertext: %s\n", cipher);

    return 0;


}



bool check_duplicate(string s)
{
    bool seen[26] = {false};
    //assume all letters, no others
    for(int i = 0; i < 26; i++ )
    {
        //all go to lowercase
        s[i] = tolower(s[i]);

        //calculate index
        int index = s[i] - 'a';

        if(seen[index])
        {
            return true;
        }
        seen[index] = true;
    }
    return false;
}
