/* Напишите функцию, которая возвращает наибольшее значение в массиве значений
типа int. Протестируйте эту функцию с помощью простой программы. */
#include <stdio.h>
#include <stdlib.h>
int high(int mas[], int n);
int main()
{
    int mas[] = {-3, -45, -26, -36, -34, -74};
    int high_num = high(mas, 6);
    printf("The highest number of massive is %d\n", high_num);
    return 0;
}

int high(int mas[], int n) // Функция возвращающая наибольшее значение в массиве
{
    int high_n = mas[0];
    for(int count = 0; count < n; count++)
    {
        if(mas[count] >= high_n)
            high_n = mas[count];
    }
    return high_n;
}
