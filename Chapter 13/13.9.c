/* Модифицируйте программу в листинге 13.3, чтобы каждое слово было пронумеровано
в соответствии с порядком его добавления в список, начиная с 1.
Позаботьтесь о том, чтобы при втором запуске программы новая нумерация
слов начиналась с того места, где была закончена пумерация при предыдущем
запуске. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41
static int count = 1; // newline counting variable
int main()
{
    FILE *fp;
    char words[MAX];
    char buf[MAX];
    if((fp = fopen("wordy.txt", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open file \"wordy.txt\".\n");
        exit(EXIT_FAILURE);
    }
     while (!feof(fp)) // first counting lines in opened file
    {
        if (fgetc(fp) == '\n') // if we have newline symbol
            count++; // increase the counter
    }
    puts("Enter words for adding in file; for exit enter symbol # at the start of the line.");
    while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    {
        fprintf(fp, "%d. %s\n", count++, words); // and increase the counter here after every newline
    }
    puts("File contents: ");
    rewind(fp); // Return to the begining of the file
   // count = 1;
    while(fscanf(fp, "%s", words) == 1)
    {
        puts(words);
    }
    puts("Done!");
    if(fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    return 0;
}
