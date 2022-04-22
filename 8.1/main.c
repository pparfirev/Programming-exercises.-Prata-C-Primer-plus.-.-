#include <stdio.h>
#include <stdlib.h>
/* Напишите программу, которая подсчитывает количество символов во входных
данных до достижения конца файла. */
int main()
{
    int count = 0; // Счетчик числа символов
    int ch; // Символ
    printf("Enter the text for symbols counting: ");
    while((ch = getchar()) != EOF)
        count++;
    printf("Text has %d symbols\n", count - 1); // Отбрасывается подсчет символа новой строки
    return 0;
}
