#include <stdio.h>
#include <stdlib.h>
/* Напишите программу, которая запрашивает рост в дюймахи имя, после чего
отображает полученную информацию в следующей форме:
Ларри, ваш рост составляет 6.208 футов
Используйте тип float, а также операцию деления /. Если хотите, можете запрашивать
рост в сантиметрах и отображать его в метрах. */
int main()
{
    char name[30];
    float len, len_m;
    printf("Please, enter your name\n");
    scanf("%s", name);
    printf("Enter your lenght in cm:");
    scanf("%f", &len);
    len_m = len / 100;
    printf("Ok, %s. Your length if metres is %.2af", name, len_m);
    return 0;
}
