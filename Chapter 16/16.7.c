/* Ниже приведена часть программы, использующей функцию с переменным числом
аргументов:
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void show_array(const double ar[] , int n);
double *new_d_array(int n, ...);
int main()
{
    double *pl;
    double *р2;
    pl = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(pl, 5);
    show_array(p2, 4);
    free(pl);
    free(p2);
    return 0;
}
Функция new_d_array() принимает аргумент типа int и переменное количество
арментов double. Она возвращает указатель на блок памяти, выделенный
функцией malloc(). Аргумент int задает количество элементов, которые должны
быть в динамическом массиве, а значения double предназначены для инициализации
элементов, при этом первое значение присваивается первому элемен-
ту, второе — второму и т.д. Завершите программу, предоставив код для функций
show_array() и new_d_array().*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void show_array (const double ar[] , int n);
double *new_d_array(int n, ...);
int main()
{
    double * p1;
    double * p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);
    return 0;
}
void show_array(const double ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%g ", ar[i]);
    putchar('\n');
}
double *new_d_array(int n, ...)
{
    va_list(ap); // Initializing object to store
    double *pt;
    va_start(ap, n); // initializing ap and list of arguments
    pt = (double *) malloc(n * sizeof(double)); // memory allocation to n elements of size double
    for(int i = 0; i < n; i++)
        pt[i] = va_arg(ap, double); // access to each element
    va_end(ap); // clearing
    return pt;
}
