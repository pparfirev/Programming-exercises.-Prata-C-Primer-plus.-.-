/* Напишите программу, которая читает две строки с двоичным представлением
как аргументы командной строки и выводит результаты применения операции ~
к каждому числу, а также результаты применения операций &, | и ^ к паре чисел.
Отобразите результаты в виде двоичных строк. (Если среда командной строки
недоступна, обеспечьте в программе интерактивный ввод строк.) */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
int bintoint(char *p);
char *itobs(int, char *);
int main(int argc, char *argv[])
{
    int n1, n2;
    char bstr[8 * sizeof(int) + 1];
    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s binary number 1 and binary number 2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    n1 = bintoint(argv[1]);
    n2 = bintoint(argv[2]);
    printf("~%s == %s\n", argv[1], itobs(~n1, bstr));
    printf("~%s == %s\n", argv[2], itobs(~n2, bstr));
    printf("%s & %s == %s\n", argv[1], argv[2], itobs((n1 & n2), bstr));
    printf("%s | %s == %s\n", argv[1], argv[2], itobs((n1 | n2), bstr));
    printf("%s ^ %s == %s\n", argv[1], argv[2], itobs((n1 ^ n2), bstr));
    //printf("well number %s\n", argv[1]);
    return 0;
}
int bintoint(char *p)
{
    int val = 0;
    while(*p != '\0')
        val = 2 * val + (*p++ - '0');
        return val;
}
char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for(i = size - 1; i >= 0; i--, n >>= 1)
    {
        ps[i] = (01 & n) + '0'; //ASCII intepretation
    }
    ps[size] = '\0';
    return ps;
}


