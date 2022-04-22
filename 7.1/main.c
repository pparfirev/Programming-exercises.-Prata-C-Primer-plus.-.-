#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>
/* Напишите программу, которая читает входные данные до тех пор, пока не встретится
символ #, а затем отображает количество прочитанных пробелов, количество
символов новой строки и количество всех остальных символов. */

int main()
{
    char ch;
    int spaces = 0;
    int lines = 0;
    int symb = 0;
    printf("Enter the text for analisys, and enter '#' at the end.\n");
    while((ch = getchar()) != '#') // Цикл продолжается пока не будет введен #
    {
        if(ch != '\n') // Символ новой строки не виден, поэтому не входит в подсчет
        symb++;
        if(ch == ' ') // Если символ пробельный, то увеличивается счетчик пробелов
            spaces++;
        if(ch == '\n') // Если новая строка, то счетчик символов новой строки
            lines++;
    }
    printf("In your text %d all symbols, %d lines and %d spaces.\n", symb, lines, spaces);
    return 0;
}
