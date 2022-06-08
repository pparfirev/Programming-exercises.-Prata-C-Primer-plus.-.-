#include <stdio.h>
#include <stdlib.h>
/* 2. Напишите функцию по имени chline(ch, i, j), которая выводит требуемый
символ в столбцах с i по j. Протестируйте эту функцию с помощью простого
драйвера. */
void chline(char ch, int i, int j);
int main()
{
    char symb;
    int x, y;
    printf("Enter the symb and number of coloumns: \n");
    scanf("%c%d%d", &symb, &x, &y);
    chline(symb, x, y);
    return 0;
}
void chline(char ch, int i, int j)
{
    int count;
    for(count = 1; count < i; count++)
        printf("_");
    for(count = i; count <= j; count++)
            putchar(ch);

}
