/* Воспользуйтесь одной из функций копирования из упражнения 2 для копирования
элементов с 3-го по 5-й семиэлементного массива в массив, состоящий из
трех элементов. Саму функцию изменять не нужно; просто подберите правильные
фактические аргументы. (Фактическими аргументами не обязательно должны
быть имя массива и его размер. Ими только должны быть адрес элемента
массива и количество обрабатываемых элементов.) */
#include <stdio.h>
#include <stdlib.h>
void copy_ptr(double *copy, double *origin, int n);
int main()
{
    double source[7] = {1.1,2.2,5.3,4.4,5.5,6.6,7.7}; // Исходный семиэлементный массив
    double copy[3];
    printf("Source = {");
    for(int count = 0; count < 7; count++)
        printf(" %1.1f ", source[count]);
    printf("}\n");
    printf("Before copy = {");
    for(int count = 0; count < 3; count++)
        printf(" %1.1f ", copy[count]);
    printf("}\n");
    copy_ptr(copy, (source + 2), 3); // В функцию отправляется исходный массив начиная с адреса третьего элемента (3,3)
    printf("After copy = {");
    for(int count = 0; count < 3; count++)
        printf(" %1.1f ", copy[count]);
    printf("}\n");

    return 0;
}
void copy_ptr(double *copy, double *origin, int n) // Функция копирования массивов, такая же как и в упражнении 10,2
{
    for(int count = 0; count < n; count++, copy++, origin++)
    {
        *copy = *origin;
    }
    return;
}
