#include "inverted_Search.h"

void display_database(Wlist *head[])
{
    printf("%-10s %-15s %-12s %-15s %-10s\n",
           "Index",
           "Word",
           "File Count",
           "Filename",
           "Word Count");

    for(int i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
}

int print_word_count(Wlist *head)
{
    while(head != NULL)
    {
        Ltable *Thead = head->Tlink;

        /* Print word information */
        printf("%-10d %-15s %-12d ",
               hash_function(head->word),
               head->word,
               head->file_count);

        /* Print all files of the word */
        while(Thead != NULL)
        {
            printf("%-15s %-10d\n",
                   Thead->file_name,
                   Thead->word_count);

            Thead = Thead->table_link;

            /* For next file, leave first 3 columns empty */
            if(Thead != NULL)
            {
                printf("%-10s %-15s %-12s ",
                       "", "", "");
            }
        }

        printf("\n");

        head = head->link;
    }

    return SUCCESS;
}