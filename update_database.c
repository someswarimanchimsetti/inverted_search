/*************** update_database.c ***************/

#include "inverted_Search.h"

int update_database(Wlist *head[], Flist **f_head)
{
    (void)f_head;

    char file_name[FNAME_SIZE];

    printf("Enter the database file to load: ");
    scanf("%14s", file_name);

    /* Check file availability */
    int ret = isFileEmpty(file_name);

    if(ret == FILE_NOTAVAILABLE)
    {
        printf("File %s is not available\n", file_name);
        return FAILURE;
    }

    /* Check empty file */
    if(ret == FILE_EMPTY)
    {
        printf("File %s is empty\n", file_name);
        return FAILURE;
    }

    /* Load saved database */
    ret = load_database(head, file_name);

    if(ret == FAILURE)
    {
        printf("Failed to load database\n");
        return FAILURE;
    }

    printf("Database updated successfully\n");

    return SUCCESS;
}