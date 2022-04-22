#include <stdio.h>
#include <stdlib.h>
/* В американской системе единиц измерений объема пинта равна 2 чашкам, чашка
— 8 унциям, унция — 2 столовым ложкам, а столовая ложка — 3 чайным ложкам.
Нанишите программу. которая предлагает ввести объем в чашках и отоб-
ражет эквивалентные значения в пинтах, унциях, столовых ложках и чайных
ложках. Почему для этой программы тип с плавающей запятой подходит больше,
чем целочисленный? */

int main()
{
    float pints, cups, ounce, b_spoon, lil_spoon;
    printf("Enter the volume in cups:");
    scanf("%f", &cups);
    pints = cups / 2;
    ounce = cups * 8;
    b_spoon = ounce * 2;
    lil_spoon = b_spoon * 3;
    printf("In %f cups %f pints, %f ounces, %f tablespoons, %f tea spoons\n", cups, pints, ounce, b_spoon, lil_spoon);
    return 0;
}
