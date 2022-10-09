/* Напишите программу копирования файлов, которая предлагает пользователю
ввести имя текстового файла. выступающего в роли исходного, и имя выходного
файла. Программа должна использовать функцию toupper() из ctype.h
для перевода текста в верхний регистр во время его записи в выходной файл.
Применяйте стандартный ввод-вывод и текстовый режим. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 255
int main()
{
    FILE *fp;
    FILE *in;
    char Or_filename[SIZE];
    char Copy_filename[SIZE];
    char ch;
    printf("Enter the original filename: ");
    gets(Or_filename); // put filename from
    if((fp = fopen(Or_filename, "r")) == NULL)
    {
        printf("Can't open original file %s\n", Or_filename);
        exit(EXIT_FAILURE);
    }
    printf("Now enter the file for copy: ");
    gets(Copy_filename);
    if((in = fopen(Copy_filename, "w")) == NULL) // stdinn setups
    {
        fprintf(stderr, "Can't open copying file  \"%s\"\n", Copy_filename);
        exit(EXIT_FAILURE);
    }
     while ((ch = getc(fp)) != EOF) // get symbols from origin file, until EOF
    {
        ch = toupper(ch); // Transformise symbol to upper
        putc(ch, in); // Enter symbol to copy file
    }
    fclose(fp);
    fclose(in);
    return 0;
}
