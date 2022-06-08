/* Напишите программу, которая инициализирует двумерный массив значений
типа double и использует одну из функций копирования из упражнения 2 для
его копирования во второй двумерный массив. (Поскольку двумерный массив -
это массив массивов, функция для копирования одномерных массивов может
применятся с каждым подмассивом.) */
#include <stdio.h>
#include <stdlib.h>
void copy_arr(double copy[][5], double origin[][5], int n);
int main()
{
    double source[2][5] = {{1.1,2.2,3.3,4.4,5.5}, {6.6,3.7,8.8,9.9,10.0}};
    double copy[2][5];
    int x_count = 0;
    int y_count = 0;
    printf("Before source = {");
    for(int x_count = 0; x_count < 2; x_count++) // Циклы для отображения двумерных массивов (исходный)
    {
        printf("\n");
         for(int y_count = 0; y_count < 5; y_count++)
            printf(" %1.1f ", source[x_count][y_count]);
    }
    printf("};\n");
    printf("Before copy = {");
    for(int x_count = 0; x_count < 2; x_count++) // копируемый до
    {
        printf("\n");
         for(int y_count = 0; y_count < 5; y_count++)
            printf(" %1.1f ", copy[x_count][y_count]);
    }
    printf("};\n");
    copy_arr(copy, source, 2);
    printf("After copy = {");
     for(int x_count = 0; x_count < 2; x_count++) // копируемый после
    {
        printf("\n");
         for(int y_count = 0; y_count < 5; y_count++)
            printf(" %1.1f ", copy[x_count][y_count]);
    }
    printf("};\n");

    return 0;
}
void copy_arr(double copy[][5], double origin[][5], int n)
{
    int count_x = 0;
    int count_y = 0;
    for(count_x = 0; count_x < n; count_x++) // Цикл поэлементного копирования
    {
        for(count_y = 0; count_y < 5; count_y++)
            copy[count_x][count_y] = origin[count_x][count_y];
    }
    return;
}
