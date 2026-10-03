#include "inverted_Search.h"

void write_databasefile(Wlist *head, FILE **databasefile)
{
    while(head != NULL)
    {
        fprintf(*databasefile, "#%d;", hash_function(head->word));

        fprintf(*databasefile, "%s;", head->word);

        fprintf(*databasefile, "%d;", head->file_count);

        Ltable *Thead = head->Tlink;

        while(Thead != NULL)
        {
            fprintf(*databasefile, "%s;", Thead->file_name);

            fprintf(*databasefile, "%d;", Thead->word_count);

            Thead = Thead->table_link;
        }

        fprintf(*databasefile, "#\n");

        head = head->link;
    }
}