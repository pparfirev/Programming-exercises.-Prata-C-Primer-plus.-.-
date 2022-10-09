/* global.c -- использование внешней переменной */
#include <stdio.h>
#include <stdlib.h>
//int units = 0; // External variable
int critic(int n);
int main()
{
    int units = 0; // Optional second add
    printf("How much pounds in barrel in oil?\n");
    scanf("%d", &units);
    while(units != 56)
    {
        units = critic(units);
        if(units == 56)
            break;
    }
    printf("You know that!\n");
    return 0;
}
int critic(int n)
{
    // optional add variable declaration omitted
    printf("Try again!\n");
    scanf("%d", &n);
    return n;
}
