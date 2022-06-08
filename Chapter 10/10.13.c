/* Напишите программу, которая предлагает пользователю ввести три набора по
пять чисел double. (Для простоты можете полагать, что пользователь отвечает
корректно и не вводит нечисловые данные.) Программа должна выполнять все
перечисленные ниже действия.
а. Хранить информацию в массиве 3х5.
б. Вычислять среднее для каждого набора из пяти значений.
в. Вычислять среднее для всех значений.
г. Определять наибольшее из 15 значений.
д. Выводить результаты на экран.
Каждая значительная задача должна решаться посредством отдельной функции
с использованием традиционного в языке С подхода к обработке массивов. Выполните
задачу б) с помощью функции, которая вычисляет и возвращает среднее
значение одномерного массива; воспользуйтесь циклом для вызова этой функции
три раза. Функции, реализующие остальные задачи, должны принимать в
качестве аргумента массив целиком, а функции, выполняющие задачи в) и г),
должны возвращать ответ в вызывающую программу. */
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3 // Размеры массива заранее прописаны
#define COLS 5
void mas_v(double view[ROWS][COLS]); // Объявление функции отображения массива
void mas_mid(double view[][COLS], int x); // Среднее значение строки массива
double mid_t(double mid[ROWS][COLS]);  // Среднее значение всех элементов массива
double max_el(double mid[ROWS][COLS]); // Вывод максимального элемента массива
int main()
{
    double mas[ROWS][COLS];
    printf("Enter the 1-st pack of 5 double numbers: "); // Ввод каждой строки массива осуществляется по порядку
    for(int i = 0; i < COLS; i++)
        scanf("%lf", &mas[0][i]);
    printf("Enter the 2-st pack of 5 double numbers: ");
    for(int i = 0; i < COLS; i++)
        scanf("%lf", &mas[1][i]);
    printf("Enter the 3-rd pack of 5 double numbers: ");
    for(int i = 0; i < COLS; i++)
        scanf("%lf", &mas[2][i]);
    printf("Your massive is mas[] = {"); // Для наглядности производится вывод введенного массива
    mas_v(mas);
    for(int rows = 0; rows < ROWS; rows++) // Среднее значение для каждого набора из пяти значений осуществяется через цикл
        mas_mid(mas, rows);
    double mid_value = mid_t(mas);
    printf("Middle value of all elements of massive %.2lf\n", mid_value);
    double max = max_el(mas);
    printf("Max value of all massive's elements is %.2lf\n", max);
    return 0;
}
void mas_v(double view[ROWS][COLS]) // Отображение массива
{
    for(int x_count = 0; x_count < ROWS; x_count++) // Циклы для отображения двумерных массивов
    {
        printf("\n");
         for(int y_count = 0; y_count < COLS; y_count++)
            printf(" %.2lf ", view[x_count][y_count]);
    }
    printf("};\n");
}
void mas_mid(double view[][COLS], int x)
{
    double mid = 0, sum = 0;
    for(int i = 0; i < COLS; i++)
     sum += view[x][i]; // сумма всех элементов строки
    mid = sum / COLS; // Расчет среднего значения
    printf("The mid value of row %d is %.2lf\n", x, mid);
    return mid;
}
double mid_t(double mid[ROWS][COLS])
{
    double midle = 0, sum = 0;
    for(int x = 0; x < ROWS; x++)
    {
    for(int i = 0; i < COLS; i++)
        sum += mid[x][i]; // сумма всех элементов массива
     midle = sum / (ROWS * COLS); // расчет среднего арифметического
    }
    return midle;
}
double max_el(double mid[ROWS][COLS])
{
    double high_n = mid[0][0]; // Начальное значение максимального элемента [0][0]
    for(int x = 0; x < ROWS; x++)
    {
    for(int y = 0; y < COLS; y++)
    {
        if(mid[x][y] >= high_n) // поэлементное сравнение значений. Если следующее больше, "прошлого наибольшего"
            high_n = mid[x][y]; // То присваивается новое наибольшее значение
    }
    }
    return high_n;
}
