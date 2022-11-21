/* Напишите программу, которая реализует меню с использованием массива указателей
на функции. Например, выбор пункта а в меню должен активизировать
функцию, на которую указывает первый элемент массива. */
#include <stdio.h>
#include <stdlib.h>
void *func1(int, int);
void *func2(int, int);
void *func3(int, int);
void *func4(int, int);
typedef int (*Fmas)(int, int);

int main()
{
    char menu;
    Fmas pf[4] = {func1, func2, func3, func4};
    printf("Choose the function menu or press q to exit: \n");
    printf("a.func1 (2 + 2)\t\tb.func2(2 - 2)\nc.func3(2 * 2)\t\td.func4(2 / 2)\n");
    while((menu = getchar()) != -1 && menu != 'q')
    {
         while(getchar() != '\n')
            continue; // СleanUp enter string
        switch(menu)
        {
            case 'a': pf[0](2, 2);
            break;
            case 'b': pf[1](2, 2);
            break;
            case 'c': pf[2](2, 2);
            break;
            case 'd': pf[3](2, 2);
            default: puts("Wrong func, enter the right symb or press q to exit.");
            break;
        }
        printf("Choose the function menu or press q to exit: \n");
        printf("a.func1 (2 + 2)\t\tb.func2(2 - 2)\nc.func3(2 * 2)\t\td.func4(2 / 2)\n");
    }
    printf("Program Closed\n");
    return 0;
}
void *func1(int x, int y)
{
    printf("2 + 2 = %d\n", (x + y));
}
void *func2(int x, int y)
{
    printf("2 - 2 = %d\n", (x - y));
}
void *func3(int x, int y)
{
    printf("2 * 2 = %d\n", (x * y));
}
void *func4(int x, int y)
{
    printf("2 / 2 = %d\n", (x / y));
}

