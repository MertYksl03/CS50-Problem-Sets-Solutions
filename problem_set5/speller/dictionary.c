// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
node *table[N] = {NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_number = hash(word);
    for (node *tmp = table[hash_number]; tmp!=NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
     
    return (toupper(word[0]) - 'A');
    
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char buffer[LENGTH];
    int hash_number = 0;

    FILE *input = fopen(dictionary, "r");
    while (fscanf(input, "%s", buffer) != EOF)
    {
        hash_number = hash(buffer);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(input);
            return false;
        }

        strcpy(n->word, buffer);
        n->next = NULL;
        if (table[hash_number] != NULL)
        {
            n->next = table[hash_number];
        }
        table[hash_number] = n;
    }
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int word_number = 0;
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];

        while (n != NULL)
        {
            n = n->next;
            word_number++;
        }

    }
    return word_number;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
   for (int i = 0; i < N; i++)
   {
        node *head_pointer = table[i];

        node *cursor = head_pointer;

        while (cursor != NULL)
        {
            node *tmp = cursor;

            cursor = cursor->next;

            free(tmp); 
        }
   }
   return true;
}
