/* Напишите программу, которая позволяет ввести строку. Программа затем должна
заталкивать в стек символы строки по одному (см. вопрос для самоконтроля
под номером 5), выталкивать символы из стека и, наконец, отображать их. В результате
символы отображаются в обратном порядке. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "17.5.h"
#define SLEN 81
char *s_gets(char *st, int n);
int main()
{
    Stack stch;
    char temp[SLEN];
    int i;
    char ch;

    InitializeStack(&stch);
    printf("Enter a line (an empty line to quit): ");
    while(s_gets(temp, SLEN) && temp[0] != '\0')
    {
        i = 0;
        while(temp[i] != '\0' && !FullStack(&stch))
            Push(temp[i++], &stch);
        while(!EmptyStack(&stch))
        {
            Pop(&ch, &stch);
            putchar(ch);
        }
        putchar('\n');
        printf("Enter next line (an empty line to quit): ");
    }
    puts("Done!");
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n'); // Look for newline
        if(find) // if the address is not NULL
            *find = '\0'; // place a null character there
        else
            while(getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}
