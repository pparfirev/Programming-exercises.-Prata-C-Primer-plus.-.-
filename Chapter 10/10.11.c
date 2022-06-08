/* Напишите программу, которая объявляет массив 3х5 значений типа int и инициализирует
его значениями по вашему выбору. Программа должна вывести эти
значения, удвоить все значения, после чего вывести новые значения. Напишите
одну функцию для вывода значений и еще одну для удваивания значений. В качестве
аргументов функции должны принимать имя массива и количество
строк. */
#include <stdio.h>
#include <stdlib.h>
#define COLS 5
void mult_mas(int n, int mas[n][COLS]); // Объявление функции удвоения элементов массива
void mas_v(int n, int mas[n][COLS]); // Объявление функции отображения массива
int main()
{
    int source[3][COLS] = {{1,2,3,4,5},
                          {5,4,3,2,1},
                          {6,7,8,9,0}};
    printf("Before sourse[] = {");
    mas_v(3, source);
    mult_mas(3, source);
    printf("After sourse[] = {");
    mas_v(3, source);
    return 0;
}
void mas_v(int n, int mas[n][COLS]) // Отображение массива
{
    for(int x_count = 0; x_count < n; x_count++) // Циклы для отображения двумерных массивов
    {
        printf("\n");
         for(int y_count = 0; y_count < COLS; y_count++)
            printf(" %d ", mas[x_count][y_count]);
    }
    printf("};\n");
}
void mult_mas(int n, int mas[n][COLS]) // удвоение элементов массива
{
    for(int count_x = 0; count_x < n; count_x++) // Цикл поэлементного умножения
    {
        for(int count_y = 0; count_y < COLS; count_y++)
            mas[count_x][count_y] *= 2;
    }
    return;
}
