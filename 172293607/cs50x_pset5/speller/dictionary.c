
// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;
// TODO: Choose number of buckets in hash table
const unsigned int N = 26;


// Hash table
node *table[N];
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashvalue = hash(word);
    node *cursor = table[hashvalue];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word)==0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    //return true for wordss actually in the dictionary
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c ;
    while (*word != 0)
    {
        c = *word ++;
        c = tolower(c);
        hash = ((hash << 5) + hash) + c;
    }
    return hash%N;
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }
    //initialize word buffer
    char word[LENGTH+1];
    //create a new node to store that particular word inside of your hash table
    //use malloc, allocate memory
    //read strings from file
    while(fscanf(source, "%s", word) != EOF)
    {
        node *n = (node*)malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(source);
            return false;
        }
        strcpy (n -> word, word);
        int hashvalue = hash(word);
        n -> next = table[hashvalue];
        table[hashvalue] = n;
    }
    fclose(source);
    return true;
}



// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int n = 0;
    for (unsigned int i = 0; i < N; i++ )
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            n ++;
            cursor = cursor -> next;
        }
    }
    // TODO
    return n;
}



// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //call any memory you been using malloc and return true id its success
//repeat the process for every one of the linked list
//in the hash table
    for(unsigned int i = 0; i < N; i ++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        //free(cursor);
    }

    return true;
}
