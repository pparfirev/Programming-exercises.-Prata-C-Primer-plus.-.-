/* Программы, работающие с аргументами командной строки, полагаются на то,
что пользователь помнит, как их правильно запускать. Перепишите программу
из листинга 13.2 так, чтобы вместо использования аргументов командной стро-
ки она предлагала пользователю ввести необходимую информацию. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 25
int main()
{
    FILE *in, *out; // two pointers on FILE
    int ch;
    char First_filename[LEN];
    char Sec_filename[LEN];
    char name[LEN]; // place for output name file
    int count = 0;
    printf("Enter the first filename: ");
    gets(First_filename); // put filename from
    if((in = fopen(First_filename, "rb")) == NULL) // stdinn setups
    {
        fprintf(stderr, "Can't open file \"%s\"\n", First_filename);
        exit(EXIT_FAILURE);
    }
    printf("Enter the second filename: ");
    gets(Sec_filename); // put filename from
    if((out = fopen(Sec_filename, "rb")) == NULL) // stdinn setups
    {
        fprintf(stderr, "Can't open file \"%s\"\n", Sec_filename);
        exit(EXIT_FAILURE);
    }
    // stdout setups
    strncpy(name, First_filename, LEN - 5); // coping filename
    name[LEN - 5] = '\0';
    strcat(name, ".txt"); // adding .txt
    if((out = fopen(name, "w")) == NULL) // opening file for recording
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    while((ch = getc(in)) != EOF) // coping data
        if(count++ % 3 == 0)
        putc(ch, out); // entering every third symbol
    if(fclose(in) != 0 || fclose(out) != 0) // cleaning
        fprintf(stderr, "Error closing files.\n");
    return 0;
}
