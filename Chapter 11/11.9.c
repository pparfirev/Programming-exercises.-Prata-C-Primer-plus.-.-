/* Напишите функцию, которая заменяет содержимое указанной строки этой же
строкой, но с обратным порядком следования символов. Протестируйте функцию
в завершенной программе, которая использует цикл для передачи входных
значений созданной функции. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
void *str_rev(char *str1);
char *s_gets(char *st, int n);
int main()
{
    char text1[SIZE];
    //char *answer;
    puts("Enter the text for string:");
    while(s_gets(text1, SIZE) && text1[0] != '\0')
    {
        puts("Before:");
        puts(text1);
        str_rev(text1);
            puts("After:");
            puts(text1);
        puts("Enter the new text for string:");
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
void *str_rev(char *str1)
{
    int L = strlen(str1) - 1;
    int y = L;
    char str1_new[SIZE]; // temporary massive
    for(int i = 0; i <= L; i++, y--)
    {
        str1_new[i] = str1[y]; // appropriation to temp massive, from last to first
    }
    for(int i = 0; i <= L; i++)
        str1[i] = str1_new[i]; // changing original massive
    return 0;
}
