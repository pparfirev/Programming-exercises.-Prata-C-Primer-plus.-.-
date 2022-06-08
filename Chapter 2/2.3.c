#include <stdio.h>
#include <stdlib.h>
/* Ќапишите программу, котора€ преобразует ваш возраст в полных годах в количество
дней и отображает на экране оба значени€. Ќе обращайте внимани€ на
високосные годы. */

int main()
{
    int age, age_d;
    age = 27;
    age_d = 27 * 365;
    printf("Age is %d.\nAge in days is %d.\n", age, age_d);
    return 0;
}
