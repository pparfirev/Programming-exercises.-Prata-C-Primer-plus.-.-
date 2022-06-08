#include <stdio.h>
#include <stdlib.h>
/* Воспользуйтесь вложенными циклами, чтобы написать программу, которая выводит
следующую последовательность символов:
F
FE
FED
FEDC
FEDCB
FEDCBA */

int main()
{
    int n, m;
    char c;
    for(n = 0; n < 6; n++)
{
    for (m = 0, c = 'F'; m <= n; m++, c--)
printf("%c", c);

printf("\n");
}
    return 0;
}
