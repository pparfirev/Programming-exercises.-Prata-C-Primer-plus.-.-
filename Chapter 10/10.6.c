/* 6. Напишите функцию, которая изменяет порядок следования содержимого массива
значений типа double на противоположный и протестируйте ее в простой
программе. */
#include <stdio.h>
#include <stdlib.h>
void reverse(double mas[], int n);
int main()
{
    double mas[] = {-13.45, -45.45, -248.26, -654.36, 9448.34, -10.74};
    int count = 0;
    printf("Before mas[] = {");
    while(count < 6)
    {
        printf(" %1.2f ", mas[count]);
        count++;
    }
    printf("}\n");
    reverse(mas, 6);
    count = 0;
    printf("After mas[] = {");
    while(count < 6)
    {
        printf(" %1.2f ", mas[count]);
        count++;
    }
    printf("}\n");
    return 0;
}

void reverse(double mas[], int n) // Функция по расстановке элемента массивов в обратном порядке
{
    int rev = n - 1;
    double mas_t[n]; // Создание временного массива для помещения в него элементов в обратном порядке
    for(int count = 0; count < n; count++, rev--)
        *(mas_t + count) = mas[rev];
        for(int count = 0; count < n; count++, mas++) // Копирование элементов из резервного массива в основной
        *mas = mas_t[count];
    return 0;
}
