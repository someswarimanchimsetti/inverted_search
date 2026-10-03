#include "inverted_Search.h"

int save_database(Wlist *head[])
{
    char file_name[FNAME_SIZE];

    printf("Enter the filename to save database: ");
    scanf("%14s", file_name);

    FILE *fptr = fopen(file_name, "w");

    if(fptr == NULL)
    {
        printf("Unable to open file %s\n", file_name);
        return FAILURE;
    }

    for(int i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            write_databasefile(head[i], &fptr);
        }
    }

    fclose(fptr);

    printf("Database saved successfully in %s\n", file_name);

    return SUCCESS;
}