#include "inverted_Search.h"

char *file_name;

void create_database(Flist *f_head, Wlist *head[])
{
    while(f_head != NULL)
    {
        read_datafile(f_head, head, f_head->file_name);

        f_head = f_head->link;
    }
}


Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    (void)file;

    FILE *fptr = fopen(filename, "r");

    if(fptr == NULL)
    {
        printf("Unable to open file %s\n", filename);
        return NULL;
    }

    /* Store current filename */
    file_name = filename;

    char word[WORD_SIZE];

    /* Read each word */
    while(fscanf(fptr, "%14s", word) == 1)
    {
        int flag = 1;

        /* Find hash index */
        int index = hash_function(word);

        /* Check whether word already exists */
        Wlist *temp = head[index];

        while(temp != NULL)
        {
            if(strcmp(temp->word, word) == 0)
            {
                /* Word already exists */
                update_word_count(&temp, filename);

                flag = 0;
                break;
            }

            temp = temp->link;
        }

        /* Word does not exist */
        if(flag == 1)
        {
            if(insert_at_last(&head[index], word) == FAILURE)
            {
                fclose(fptr);
                return NULL;
            }
        }
    }

    fclose(fptr);

    return NULL;
}


int update_word_count(Wlist **head, char *filename)
{
    Ltable *temp = (*head)->Tlink;

    /* Check whether file already exists */
    while(temp != NULL)
    {
        if(strcmp(temp->file_name, filename) == 0)
        {
            temp->word_count++;
            return SUCCESS;
        }

        temp = temp->table_link;
    }

    /* File is different, create new Ltable */
    Ltable *new = malloc(sizeof(Ltable));

    if(new == NULL)
    {
        return FAILURE;
    }

    strcpy(new->file_name, filename);

    new->word_count = 1;
    new->table_link = NULL;

    /* Increase file count */
    (*head)->file_count++;

    /* If first file */
    if((*head)->Tlink == NULL)
    {
        (*head)->Tlink = new;
    }
    else
    {
        /* Find last Ltable node */
        temp = (*head)->Tlink;

        while(temp->table_link != NULL)
        {
            temp = temp->table_link;
        }

        temp->table_link = new;
    }

    return SUCCESS;
}