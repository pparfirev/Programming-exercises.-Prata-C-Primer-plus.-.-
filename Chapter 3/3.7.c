#include <stdio.h>
#include <stdlib.h>
/* В дюйме имеется 2.54 сантиметра. Напишите программу, которая предлагает
ввести рост в дюймах, после чего выводит на экран этот рост в сантиметрах.
Либо, если вам так больше нравится, программа может запрашивать рост в сантиметрах
и переводить его в дюймы. */
int main()
{
    float inch = 2.54;
    float length;
    printf("Enter length in santimetres:");
    scanf("%f", &length);
    float len_inch = length / inch;
    printf("In %f santimetres is %f inches", length, len_inch);

    return 0;
}
