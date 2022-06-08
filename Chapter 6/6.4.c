#include <stdio.h>
#include <stdlib.h>
/* Воспользуйтесь вложенными циклами, чтобы написать программу, которая выводит
следующую последовательность символов:
А
BC
DEF
GНIJ
KLMNO
PQRSTU */

int main()
{
    int n, m;
    char c = 'A';
    for(n = 0; n < 6; n++)
        {
        for (m = 0; m <= n; m++, c++)
        printf("%c", c);

    printf("\n");
        }
    return 0;
}
