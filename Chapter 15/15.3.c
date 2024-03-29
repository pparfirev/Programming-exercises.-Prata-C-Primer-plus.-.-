/* Напишите функцию, которая принимает аргумент типа int и возвращает количество
включенных битов в нем. Протестируйте функцию в какой-нибудь программе. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
int onbits(int n);
int main()
{
    int number;
    char bin_str[CHAR_BIT *sizeof(int) + 1];
    printf("Enter the integer number to analyze or enter non numeric value to exit: \n");
        while(scanf("%d", &number) == 1)
    {
        itobs(number, bin_str);
        printf("%d has %d enabled bits", number, onbits(number));
        //show_bstr(bin_str);
        putchar('\n');
    }
    return 0;
}

int onbits(int n)
{
    static const int size = CHAR_BIT * sizeof(int);
    int ans = 0; // answer counter
    int i;
    for(i = 0; i < size; i++, n >>= 1)
    {
        if((1 & n) == 1) // Bitwise AND for counting enabled bits in number
            ans++;
    }
    return ans;
}
