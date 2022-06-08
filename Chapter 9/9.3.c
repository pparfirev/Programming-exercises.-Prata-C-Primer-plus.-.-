#include <stdio.h>
#include <stdlib.h>
/* 3. Напишите функцию, которая принимает три аргумента: символ и два целых числа.
Символ предназначен для вывода. Первое целое значение задает количество
указанных символов в строке, а второе целое число устанавливает количество
таких строк. Напишите программу, в которой используется эта функция. */
void ch_func(char ch, int x, int y);
int main()
{
    char symb;
    int a, b;
    printf("Enter the symb: \n");
    symb = getchar();
    printf("Enter the quantity symbol in row and quantity of cols\n");
    scanf("%d%d", &a, &b);
    ch_func(symb, a, b);
    return 0;
}
void ch_func(char ch, int x, int y)
{
    int count;
    int n;
    for(count = 0; count < y; count++)
    {
      //putchar(ch);
        for(n = 0; n < x; n++)
            putchar(ch);
            putchar('\n');
    }
    return;
}
