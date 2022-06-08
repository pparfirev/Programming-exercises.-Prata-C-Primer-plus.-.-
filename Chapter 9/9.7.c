#include <stdio.h>
#include <stdlib.h>
/* Напишите программу, которая читает символы из стандартного ввода вплоть
до конца файла. Для каждого символа программа должна сообщать, является
ли он буквой. Если символ — буква, программа вдобавок должна сообщать ее
порядковый номер в алфавите. Например, буквы с и С будут иметь номер 3.
Предусмотрите в программе функцию, которая принимает символ в качестве
аргумента и возвращает его порядковый номер в алфавите, если он является
буквой, и -1 в противном случае. */
int conv(char lett);
int main()
{
    char symb;
    int num;
    printf("Enter the symbols for analysys: \n");
    while((symb = getchar()) != EOF)
    {
        num = conv(symb);
        printf("%c is '%d'\n", symb, num);
    }
    printf("Program Closed.\n");
    return 0;
}

int conv(char lett)
{
    int code;
    int count;
    if((lett >= 65 && lett <= 90)) // ANSI a = 97, A = 65
        code = lett - 64;
    else if(lett >= 97 && lett <= 122)
        code = lett - 96;
    else
        code = -1;
    return code;
}
