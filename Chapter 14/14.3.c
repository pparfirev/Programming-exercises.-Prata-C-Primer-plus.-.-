/* Измените программу из листинга 14.2, чтобы она сначала выводила описания
книг в том порядке, в каком они вводились, затем в алфавитном порядке по названиям
и, наконец, в порядке возрастания цены. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *s_gets(char *st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 // max books quality
struct book { // book template
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
} books[MAXBKS];
int main()
{
    struct book book_tmp; // Temp structure for copying
    struct book library[MAXBKS]; // massive of structures type of book
    int count = 0;
    int index;
    printf("Enter the name of book: \n");
    printf("Or enter the empty string to stop entering.\n");
    while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author name: \n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the price: \n");
        scanf("%f", &library[count++].value);
        while(getchar() != '\n')
            continue; // Clean input string
        if(count < MAXBKS)
            printf("Enter the next name of book: \n");
    }
    if(count > 0)
    {
        printf("Here's the catalog of your books: \n");
        for(index = 0; index < count; index++)
            printf("%s of author %s: $%.2f\n", library[index].title, library[index].author,
                    library[index].value);
        puts("\n\nHere is the catalog sorted by alphabet: "); // Bubble sorting
        for(index = 0; index < count; index++)
            for(int i = 0; i < count; i++)
                if(strcmp(library[i + 1].title, library[i].title) < 0) // Two strings comprassion
                {
                    book_tmp = library[i];
                    library[i] = library[i + 1];
                    library[i + 1] = book_tmp;
                }
        for(index = 1; index <= count; index++)
            printf("%s of author %s: $%.2f\n", library[index].title, library[index].author,
                    library[index].value);
        puts("\n\nHere is the catalog sorted by price: ");
        for(index = 0; index < count; index++) // Bubble sorting
            for(int i = 0; i < count; i++)
                if(library[i + 1].value < library[i].value) // Price comrassion
                {
                    book_tmp = library[i];
                    library[i] = library[i + 1];
                    library[i + 1] = book_tmp;
                }
        for(index = 1; index <= count; index++)
            printf("%s of author %s: $%.2f\n", library[index].title, library[index].author,
                    library[index].value);
    }
    else
        printf("No books.\n");
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n'); // NewLine searching
        if(find) // If adress doesn't NULL
            *find = '\0'; // Place ZeroSymbol
        else
            while(getchar() != '\n')
            continue; // Drop the end of the line
    }
    return ret_val;
}
