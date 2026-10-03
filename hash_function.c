#include "inverted_Search.h"

int hash_function(const char *word)
{
    int index;

    index = tolower((unsigned char)word[0]) - 'a';

    if(index >= 0 && index <= 25)
    {
        return index;
    }

    return 26;
}