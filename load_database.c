/*************** load_database.c ***************/

#include "inverted_Search.h"

int load_database(Wlist *head[], char *filename)
{
    FILE *fptr;

    int index;
    int file_count;
    int word_count;

    char word[WORD_SIZE];
    char file_name[FNAME_SIZE];

    fptr = fopen(filename, "r");

    if(fptr == NULL)
    {
        return FAILURE;
    }

    while(fscanf(fptr, "#%d;%14[^;];%d;",
                 &index,
                 word,
                 &file_count) == 3)
    {
        Wlist *new_word = malloc(sizeof(Wlist));

        if(new_word == NULL)
        {
            fclose(fptr);
            return FAILURE;
        }

        strcpy(new_word->word, word);

        new_word->file_count = file_count;
        new_word->Tlink = NULL;
        new_word->link = NULL;

        Ltable *last = NULL;

        for(int i = 0; i < file_count; i++)
        {
            if(fscanf(fptr, "%14[^;];%d;",
                      file_name,
                      &word_count) != 2)
            {
                free(new_word);
                fclose(fptr);
                return FAILURE;
            }

            Ltable *new_table = malloc(sizeof(Ltable));

            if(new_table == NULL)
            {
                free(new_word);
                fclose(fptr);
                return FAILURE;
            }

            strcpy(new_table->file_name, file_name);

            new_table->word_count = word_count;

            new_table->table_link = NULL;

            if(new_word->Tlink == NULL)
            {
                new_word->Tlink = new_table;
            }
            else
            {
                last->table_link = new_table;
            }

            last = new_table;
        }

        /* Read ending # */
        fscanf(fptr, "#");

        /* Insert word into hash table */
        if(head[index] == NULL)
        {
            head[index] = new_word;
        }
        else
        {
            Wlist *temp = head[index];

            while(temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = new_word;
        }
    }

    fclose(fptr);

    return SUCCESS;
}