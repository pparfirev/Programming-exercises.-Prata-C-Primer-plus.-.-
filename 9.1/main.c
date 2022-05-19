#include <stdio.h>
#include <stdlib.h>
/* Напишите функцию по имени min(х, у), которая возвращает меньшее из двух
значений double. Протестируйте эту функцию с помощью простого драйвера. */

double min(double x, double y);
int main()
{
    double a, b;
    double ans;
    printf("Enter 2 double numbers and I show you what is lower (or press any symb to exit): \n");
    while(scanf("%lf%lf", &a, &b) == 2)
    {
    while(a == b)
    {
        printf("Your numbers is equal, enter another: \n");
        scanf("%lf%lf", &a, &b);
    }
    ans = min(a, b);
    printf("The lower numb. is %0.2lf\n", ans);
    printf("Enter 2 double numbers and I show you what is lower (or press q for exit): \n");
    scanf("%lf%lf", &a, &b);
    }
    printf("Program Closed.\n");
    return 0;
}
double min(double x, double y)
{
    double min_n;
    if(x > y)
        min_n = y;
    else
        min_n = x;
    return min_n;
}
