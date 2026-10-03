#include "inverted_Search.h"

int main(int argc, char *argv[])
{
    int option;

    Wlist *head[27] = {NULL};

    system("clear");

    /* Validation for CLA */
    if(argc <= 1)
    {
        printf("Enter the valid number of arguments\n");
        printf("Usage: ./a.out file1.txt file2.txt\n");
        return 0;
    }

    /* Create file linked list */
    Flist *f_head = NULL;

    /* Validate files */
    file_validation_n_file_list(&f_head, argv);

    if(f_head == NULL)
    {
        printf("No files are added to the list\n");
        printf("Hence the process got terminated\n");
        return -1;
    }

    while(1)
    {
        printf("\n");
        printf("========================================\n");
        printf("          INVERTED SEARCH MENU\n");
        printf("========================================\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Update Database\n");
        printf("4. Search\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                create_database(f_head, head);
                printf("Database created successfully\n");
                break;

            case 2:
                display_database(head);
                break;

            case 3:
                update_database(head, &f_head);
                break;

            case 4:
            {
                char word[WORD_SIZE];

                printf("Enter the word to search: ");
                scanf("%14s", word);

                int index = hash_function(word);

                search(head[index], word);

                break;
            }

            case 5:
                save_database(head);
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}