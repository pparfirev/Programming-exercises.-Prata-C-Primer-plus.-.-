/* Напишите программу, которая инициализирует массив значений типа double
и затем копирует его содержимое в три других массива. (Все четыре массива
должны быть объявлены в главной программе.) Для создания первой копии воспользуйтесь
функцией, в которой применяется форма записи с массивами. Для
создания второй копии используйте функцию, в которой применяется форма
записи с указателями и инкрементирование указателей. Первые две функции
должны принимать в качестве аргументов имя целевого массива, имя исходного
массива и количество элементов, подлежащих копированию. Третья функция
должна принимать в качестве аргументов имя целевого массива, имя исходного
массива и указатель на элемент, следующий за последним элементом в исходном
массиве. С учетом приведенных ниже объявлений вызовы функций должны выглядеть
так:
double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5);
double targetl[5];
double target2[5];
double target3[5];
copy_arr(targetl, source, 5);
copy_ptr(target2, source, 5);
copy_ptrs(target3, source, source + 5); */
#include <stdio.h>
#include <stdlib.h>
void copy_arr(double copy1[], double origin[], int n); // Первая копия, где используется функция формы записи с массивами
void copy_ptr(double *copy2, double *origin, int n); // Вторая копия, где применяется форма записи с указателями и инкрементированиями указателей
void copy_ptrs(double copy3[], double origin[], double n[]); // Третья копия должна принимать в качестве аргументов имя целевого массива, имя исходного массива и указатель на элемент
int main()
{
    double source[5] = {1.1,2.2,3.3,4.4,5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    int count = 0;
    printf("Before target1 = {");
    while(count < 5)
    {
        printf(" %1.1f ", target1[count]);
        count++;
    }
    printf("}\n");
    count = 0;
    printf("Before target2 = {");
    while(count < 5)
    {
        printf(" %1.1f ", target2[count]);
        count++;
    }
    printf("}\n");
    count = 0;
    printf("Before target3 = {");
    while(count < 5)
    {
        printf(" %1.1f ", target3[count]);
        count++;
    }
    printf("}\n");
    count = 0;
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    printf("After target1 = {");
    while(count < 5)
    {
        printf(" %1.1f ", target1[count]);
        count++;
    }
    printf("}\n");
    count = 0;
    printf("After target2 = {");
    while(count < 5)
    {
        printf(" %1.1f ", target2[count]);
        count++;
    }
    printf("}\n");
    count = 0;
    printf("After target3 = {");
    while(count < 5)
    {
        printf(" %1.1f ", target3[count]);
        count++;
    }
    printf("}\n");
    count = 0;
    return 0;
}

void copy_arr(double copy1[], double origin[], int n)
{
    int count = 0;
    while(count < n)
    {
        copy1[count] = origin[count];
        count++;
    }
    return;
}
void copy_ptr(double *copy2, double *origin, int n)
{
    for(int count = 0; count < n; count++, copy2++, origin++)
    {
        *copy2 = *origin;
    }
    return;
}

void copy_ptrs(double copy3[], double origin[], double n[])
{
    double *clone;
    clone = origin;
     for(int count = 0; clone < n; count++, copy3++, clone++, *origin++)
    {
        *copy3 = *origin;
    }
    return;
}

