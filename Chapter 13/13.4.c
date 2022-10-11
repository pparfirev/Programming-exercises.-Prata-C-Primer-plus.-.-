/* Напишите программу, которая последовательно отображает на экране содержимое
всех файлов, перечисленных в командной строке. Для управления циклом
используйте argc. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int ch; // place to store every reading symbol
    FILE *fp; // file pointer
    unsigned long n = 1;
    if(argc == 1)
    {
        printf("Using: %s name_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    while(n <= argc)
    {
        fp = fopen(argv[n], "r");
        while((ch = getc(fp)) != EOF)
        {
            putc(ch, stdout); //same as putchar(ch)
        }
    n++;
    putchar('\n');
    }
    fclose(fp);
    return 0;
}
