/* Напишите функцию по имени is_within(), которая в качестве двух своих параметров
принимает символ и указатель на строку. Функция должна возвращать
ненулевое значение, если заданный символ содержится в строке, и ноль в противном
случае. Протестируйте функцию в завершенной программе, которая использует
цикл для передачи входных значений созданной функции.*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
char *s_gets(char *st, int n);
char *is_within(const char *str, char symb);
int main()
{
    char status;
    char lit;
    char text[SIZE];
    puts("Enter the text for analysis");
    while(s_gets(text, SIZE) && text[0] != '\0')
    {
    printf("Enter the symbol to find in line:\n");
    scanf("%c", &lit);
    scanf("%*1[\n]"); // skip '\n' symbol
    status = is_within(text, lit);
    if(status == 0) // if text not founded
        printf("The litera doesn't founded\n");
    else
        printf("The litera is found at the text\n");
        puts("Enter the new text for analysis, or enter empty line for exit: ");
    }
    puts("Program Closed.");
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin); // ввод строки с клавиатуры
    if(ret_val) // если строка введена
    {
        while(st[i] != '\n' && st[i] != '\0') // инкремент до конца строки или символа новой строки
            i++; // инкремент счетчика
        if(st[i] == '\n') // если введен символ новой строки
            st[i] = '\0'; // то вводится символ окончания строки
        else // Требуется наличие words[i] == '\0'
            while(getchar() != '\n')
            continue;
    }
    return ret_val;
}
char *is_within(const char *str, char symb)
{
    int i = 0;
    while(i < SIZE)
    {
        if(str[i] == symb) // If litera founded in text
        {
            return 1; // return the address of this text
        }
        i++;
    }
    return NULL; // if not, return null
}
