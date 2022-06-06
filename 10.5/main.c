/* Напишите функцию, которая возвращает разность между наибольшим и наименьшим
элементами в массиве значений типа double. Протестируйте эту функцию с
помощью простой программы. */
#include <stdio.h>
#include <stdlib.h>
double diff(double mas[], int n);
int main()
{
    double mas[] = {-13.45, -45.45, -248.26, -654.36, 9448.34, -10.74};
    double diff_num = diff(mas, 6);
    printf("The difference between highest and lowest elements of massive is %.2lf\n", diff_num);
    return 0;
}

double diff(double mas[], int n)
{
    double high_n = mas[0]; // начальные значения для сравнения
    double low_n = mas[0];
    for(int count = 0; count < n; count++)
    {

        if(mas[count] >= high_n)
            high_n = mas[count];
        if(mas[count] <= low_n)
            low_n = mas[count];
    }
    return (high_n - low_n);
}
