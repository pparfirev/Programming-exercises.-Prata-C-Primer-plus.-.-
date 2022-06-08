#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* Напишите программу, которая читает ввод как поток символов, пока не встретит
EOF. Программа должна сообщать среднее количество букв в словах. Не считайте
пробельные символы в словах буквами. На самом деле, также не должны
учитываться и знаки препинания, но в данном упражнении об этом можно не
беспокоиться. (Для учета знаков препинания можно воспользоваться функцией
ispunct () из семейства ctype.h. */
int main()
{
    int ch; // Введенный символ
    int count_words = 0; // Количество слов
    int count_symb = 0; // Количество символов
    int count_synt = 0; // Количество знаков препинания
    int mid_symb = 0; // Среднее количество символов в слове
    printf("Enter the text for symbols counting: ");
    while((ch = getchar()) != EOF)
    {
        if(ispunct(ch))
            count_synt++; // Подсчет символов пунктуации
        else if(!(isspace(ch)) && !(ispunct(ch))) // Если не пробельный символ и не символ пунктуации
            count_symb++; // То идет подсчет символов
        else if(isspace(ch)) // Если символ пробельный
         count_words++; // то подсчет слов
    }
    mid_symb = count_symb / count_words; // Среднее количество символов высчитывается как общее количество символов деленное на количество слов
    printf("Total syntax symbols: %d; Total words: %d; Average number of letters in words: %d\n", count_synt, count_words, mid_symb);
    return 0;
}
