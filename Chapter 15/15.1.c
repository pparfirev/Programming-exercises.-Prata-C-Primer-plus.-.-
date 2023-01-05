/* Напишите функцию, которая преобразует строку с двоичным представлением в
числовое значение. Другими словами, если есть
char *pbin = "01001001";
то переменную pbin можно передать этой функции в качестве аргумента, и функция
должна возвратить значение 25 типа int. */ // There is a typo in book, in this binary value function must return value 73
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
int bintoint(char *p);
char * s_gets(char * st, int n);
bool check_val(const char *str); // Checking entering value
int main()
{
    const size_t SLEN = CHAR_BIT * sizeof(int) + 1;
    char value[SLEN];
    printf("Please enter a binary number with up to %zu digits: \n", SLEN - 1);
    while(s_gets(value, SLEN) && value[0] != '\0')
    {
        if(!check_val(value))
            puts("Binary number must contents only 0 and 1.");
        else
            printf("%s is %d\n", value, bintoint(value));
        puts("Enter the next number or enter the empty line to exit: ");
    }
    return 0;
}
bool check_val(const char *str)
{
    bool valid = true;
    while(valid && *str != '\0')
    {
        if(*str != '0' && *str != '1')
            valid = false;
        ++str;
    }
    return valid;
}
int bintoint(char *p)
{
    int val = 0;
    while(*p != '\0')
        val = 2 * val + (*p++ - '0');
        return val;
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}
