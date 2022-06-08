#include <stdio.h>
#include <stdlib.h>
/* Масса одной молекулы воды приблизительно составляет 3.Ох10^-23 грамм. Кварта
воды весит примерно 950 грамм. Напишите программу, которая предлагает ввести
значение объема воды в квартах и отображает количество молекул воды в
этом объеме. */
int main()
{
    float mol = 3.0e-23;
    int quart = 950;
    printf("Enter water volume in quarts:");
    int water;
    scanf("%d", &water);
    double qual_w = water * quart / mol;
    printf("Quality molecules in volume is: %e", qual_w);
    return 0;
}
