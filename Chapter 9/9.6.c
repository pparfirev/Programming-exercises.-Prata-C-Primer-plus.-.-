#include <stdio.h>
#include <stdlib.h>
/* Напишите и протестируйте функцию, которая принимает в качестве аргументов
адреса трех переменных double и помещает наименьшее значение в первую переменную,
среднее значение — во вторую, а наибольшее значение — в третью. */
void incr(double *low, double *mid, double *high);
int main()
{
    double a1, a2, a3;
    printf("Enter 3 float numbers or press q to exit: (wrong enter will close the progam)\n");
    while(scanf("%lf%lf%lf", &a1, &a2, &a3) == 3)
    {
        printf("First a1 = %0.2lf, a2 = %0.2lf, a3 = %0.2lf\n", a1, a2, a3);
        incr(&a1, &a2, &a3);
        printf("Now a1 = %0.2lf, a2 = %0.2lf, a3 = %0.2lf\n", a1, a2, a3);
        printf("Enter 3 float numbers or press q to exit: (wrong enter will close the progam)\n");
    }
    return 0;
}

void incr(double *low, double *mid, double *high) // Вышло не очень аккуратно
{
    double temp_l, temp_m, temp_h;
    if(*low < *mid && *low < *high)
    {
        temp_l = *low;
        if(*mid < *high)
        {
            temp_m = *mid;
            temp_h = *high;
        }
        else
        {
            temp_m = *high;
            temp_h = *mid;
        }
    }
    if(*mid < *low && *mid < *high)
    {
        temp_l = *mid;
        if(*low < *high)
        {
            temp_m = *low;
            temp_h = *high;
        }
        else
        {
            temp_m = *high;
            temp_h = *low;
        }
    }
    if(*high < *low && *high < *mid)
    {
        temp_l = *high;
        if(*low < *mid)
        {
            temp_m = *low;
            temp_h = *mid;
        }
        else
        {
            temp_m = *mid;
            temp_h = *low;
        }
    }
    *low = temp_l;
    *mid = temp_m;
    *high = temp_h;
    return;
}
