/* Напишите программу, которая читает входные данные до тех пор, пока не встретится
EOF, и выводит их на экран. Программа должна распознавать и реализовывать
следующие аргументы командной строки:
    -р Вывод входных данных в том виде, как есть.
    -u Преобразование входных данных в верхний регистр.
    -1 Преобразование входных данных в нижний регистр.
Кроме того, еcли аргумент входной строки нс указан, программа должна вести
себя так, как сели бы был задан аргумент -р. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 81
#define STRING 20

int main(int argc, char *argv[])
{
    int ch;
    if(argv[1][0] == '-')
    {
    if(argv[1][1] == 'p')
    {
        while((ch = getchar()) != EOF)
            putchar(ch);
    }
    if(argv[1][1] == 'u')
    {
        while((ch = getchar()) != EOF)
            putchar(toupper(ch));
    }
    if(argv[1][1] == 'l')
    {
        while((ch = getchar()) != EOF)
            putchar(tolower(ch));
    }
    else
    {
        while((ch = getchar()) != EOF)
            putchar(ch);
    }
    }
    elseYe
        {
        while((ch = getchar()) != EOF)
            putchar(ch);
        }
}
