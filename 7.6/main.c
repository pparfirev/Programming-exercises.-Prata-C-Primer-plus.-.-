#include <stdio.h>
#include <stdlib.h>
/* Напишите программу, которая читает входные данные, пока не встретит символ
#, и сообщает количество вхождений последовательности ei.
На заметку!
Эта программа должна “запоминать" предыдущий символ, а также текущий символ.
Проверьте ее на входной последовательности вроде “Receive your eieio award#”. */
int main()
{
    char ch;
    int ch1 = 0;
    int count = 0; // Надо всегда занулять ебучий счетчик в начале
    printf("Enter the text for analisys, and enter '#' at the end.\n");
    while((ch = getchar()) != '#') // Цикл продолжается пока не будет введен #
    {
        if(ch == 'e')
        {
            ch1 = 1;
            continue;
        }
        if(ch == 'i' && ch1)
            count++;
        ch1 = 0;
    }
    printf("Totally have %d subsequences.\n", count);
    return 0;
}
