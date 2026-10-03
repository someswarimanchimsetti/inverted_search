#include "inverted_Search.h"

int search(Wlist *head, char *word)
{
    /* Traverse Wlist */
    while(head != NULL)
    {
        /* Compare word */
        if(strcmp(head->word, word) == 0)
        {
            printf("Word %s is present in %d files\n",
                   word,
                   head->file_count);

            /* Traverse Ltable */
            Ltable *Thead = head->Tlink;

            while(Thead != NULL)
            {
                printf("In file %s %d\n",
                       Thead->file_name,
                       Thead->word_count);

                Thead = Thead->table_link;
            }

            return SUCCESS;
        }

        head = head->link;
    }

    printf("Search word not found\n");

    return FAILURE;
}