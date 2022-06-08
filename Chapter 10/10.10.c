/* Напишите функцию, которая устанавливает значение каждого элемента массива
в сумму соответствующих элементов в двух других массивах. Другими словами,
если массив 1 имеет значения 2, 4, 5 и 8, а массив 2 — значения 1, 0, 4 и 6, то эта
функция присваивает массиву 3 значения 3, 4, 9 и 14. Функция должна принимать
в качестве аргументов имена трех массивов и их размеры. Протестируйте
эту функцию с помощью простой программы. */
#include <stdio.h>
#include <stdlib.h>
void mas_sum(int n, int first[n], int sec[n], int sum[n]); // Объявление функции суммирования массивов
void view_mas(int n, int mas[n]); // Объявление функции отображения массивов
int main()
{
    int mas1[4] = {2,4,5,8};
    int mas2[4] = {1,0,4,6};
    int mas_s[4];
    printf("mas_s before = { ");
    view_mas(4, mas_s);
    mas_sum(4, mas1, mas2, mas_s);
    printf("mas_s after = { ");
    view_mas(4, mas_s);
    return 0;
}
void view_mas(int n, int mas[n])
{
    for(int count = 0; count < n; count++)
        printf("%d ", mas[count]);
    printf("};\n");
}
void mas_sum(int n, int first[n], int sec[n], int sum[n])
{
    for(int count = 0; count < n; count++)
        sum[count] = first[count] + sec[count]; // Сложение элементов 2-ух массивов и присваивание третьему
    return;
}
