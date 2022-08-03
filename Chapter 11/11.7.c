/* Функция strncpy(sl, s2, n) копирует в точности n символов из строки s2 в
строку sl, при необходимости усекая s2 или дополняя ее нулевыми символами.
Целевая строка может не содержать завершающего нулевого символа, если
длина строки s2 равна или больше n. Функция возвращает строку sl. Напишите
свою версию этой функции и назовите ее mystrncpy (). Протестируйте функцию в
завершенной программе, которая использует цикл для передачи входных
значений созданной функции. */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
char *mystrcpy(char *str1, char *str2, int n);
char *s_gets(char *st, int n);
int main()
{
    char text1[SIZE], text2[SIZE];
    char answer;
    int count;
    puts("Enter the text for first and second string:");
    while(s_gets(text1, SIZE) && s_gets(text2, SIZE) && text1[0] != '\0')
    {
        puts("Enter the quality of symbols that need to copied from text2 to text1:");
        scanf("%d", &count);
        puts("Before:");
        puts(text1);
        puts(text2);
        printf("%d\n", count);
        answer = mystrcpy(text1, text2, count);
        puts("After:");
        puts(text1);
        puts(text2);
        printf("%d\n", count);
        puts("Enter the new text for first and second string:");
    }
    puts("Program Closed.");
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin); // ââîä ñòðîêè ñ êëàâèàòóðû
    if(ret_val) // åñëè ñòðîêà ââåäåíà
    {
        while(st[i] != '\n' && st[i] != '\0') // èíêðåìåíò äî êîíöà ñòðîêè èëè ñèìâîëà íîâîé ñòðîêè
            i++; // èíêðåìåíò ñ÷åò÷èêà
        if(st[i] == '\n') // åñëè ââåäåí ñèìâîë íîâîé ñòðîêè
            st[i] = '\0'; // òî ââîäèòñÿ ñèìâîë îêîí÷àíèÿ ñòðîêè
        else // Òðåáóåòñÿ íàëè÷èå words[i] == '\0'
            while(getchar() != '\n')
            continue;
    }
    return ret_val;
}
char *mystrcpy(char *str1, char *str2, int n)
{
    for(int i = 0; i < SIZE; i++)
    {
       if(i < n) // Copying only n symbols
        str1[i] = str2[i];
       else // another symbols of first string changing by NULL
        str1[i] = '\0';
    }
    return *str1;
}
