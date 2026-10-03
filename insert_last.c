#include "inverted_Search.h"

extern char *file_name;

int insert_at_last(Wlist **head, data_t *data)
{
    /* Create new word node */
    Wlist *new = malloc(sizeof(Wlist));

    if(new == NULL)
    {
        return FAILURE;
    }

    /* Update word node */
    new->file_count = 1;

    strcpy(new->word, data);

    new->Tlink = NULL;

    new->link = NULL;

    /* Create first link table node */
    if(update_link_table(&new) == FAILURE)
    {
        free(new);
        return FAILURE;
    }

    /* If word list is empty */
    if(*head == NULL)
    {
        *head = new;

        return SUCCESS;
    }

    /* Traverse to last word node */
    Wlist *temp = *head;

    while(temp->link != NULL)
    {
        temp = temp->link;
    }

    /* Link new word node */
    temp->link = new;

    return SUCCESS;
}


int update_link_table(Wlist **head)
{
    /* Create new link table node */
    Ltable *new = malloc(sizeof(Ltable));

    if(new == NULL)
    {
        return FAILURE;
    }

    /* Update link table */
    new->word_count = 1;

    strcpy(new->file_name, file_name);

    new->table_link = NULL;

    /* Link Ltable to Wlist */
    (*head)->Tlink = new;

    return SUCCESS;
}