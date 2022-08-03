/* Напишите программу, которая читает входные данные до тех пор, пока не встретится
EOF, и выводит количество слов, количество прописных букв, количество
строчных букв, количество знаков препинания и количество-цифр. Используйте
семейство функций ctype.h. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 81
char *s_gets(char *st, int n);
void words_count(char *st, int n);
void lower_count(char *st, int n);
void upper_count(char *st, int n);
void punc_count(char *st, int n);
void num_count(char *st, int n);
int main()
{
    char text1[SIZE];
    puts("Enter the text for analysis:");
    while(s_gets(text1, SIZE) && text1[0] != '\0')
    {
        words_count(text1, strlen(text1));
        upper_count(text1, strlen(text1));
        lower_count(text1, strlen(text1));
        punc_count(text1, strlen(text1));
        num_count(text1, strlen(text1));

        puts("Enter the new text for analysis:");
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
void words_count(char *st, int n)
{
    int word = 0;
    for(int i = 0; i < n; i++)
    {
        if(isalpha(st[i]) && !(isalpha(st[i + 1]))) // if first symbol is alpha and nexi isn't
            word++; // increase word counter
    }
        printf("String has: %d words.\n", word);
}
void upper_count(char *st, int n)
{
    int upper = 0;
    for(int i = 0; i < n; i++)
    {
        if(isupper(st[i]))
           upper++;
    }
    printf("\t%d capital letters.\n", upper);
}
void lower_count(char *st, int n)
{
    int lower = 0;
    for(int i = 0; i < n; i++)
    {
        if(islower(st[i]))
           lower++;
    }
    printf("\t%d lowercase letters.\n", lower);
}
void punc_count(char *st, int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(ispunct(st[i]))
           count++;
    }
    printf("\t%d punctuation marks.\n", count);
}
void num_count(char *st, int n)
{
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        if(isalnum(st[i]) && !isalpha(st[i]))
           num++;
    }
    printf("\t%d numbers.\n", num);
}
