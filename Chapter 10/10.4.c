/* Напишите функцию, которая возвращает индекс наибольшего значения в массиве
значений типа double. Протестируйте эту функцию с помощью простой
программы. */
#include <stdio.h>
#include <stdlib.h>
double high(double mas[], int n);
int main()
{
    double mas[] = {-3.45, -45.45, -248.26, -654.36, 9448.34, 100.74};
    double high_num = high(mas, 6);
    printf("The highest number of massive is %.2lf\n", high_num);
    return 0;
}

double high(double mas[], int n) // Функция возвращающая наибольшее значение в массиве
{
    double high_n = mas[0];
    for(int count = 0; count < n; count++)
    {
        if(mas[count] >= high_n)
            high_n = mas[count];
    }
    return high_n;
}
