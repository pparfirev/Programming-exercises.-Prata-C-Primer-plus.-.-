/* Модифицируйте программу в листинге 13.1, чтобы она предлагала пользователю
ввести имя файла и читала его ответ вместе использования аргументов командной
строки. */
#include <stdio.h>
#include <stdlib.h> // exit() prototype
#include <string.h>
#define SIZE 255
int main(void)
{
    int ch; // place to store every reading symbol
    FILE *fp; // file pointer
    unsigned long count = 0;
    char filename[SIZE]; // Massive for entering filename
    printf("Enter the filename: ");
    gets(filename); // put filename from

    if((fp = fopen(filename, "r")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); //same as putchar(ch)
        count++;
    }
    fclose(fp);
    printf("\nFile have %lu symbols\n", filename, count);
    return 0;
}
