/* Напишите функцию, которая циклически сдвигает биты значения типа
unsigned int на указанное количество позиций влево. Например, функция
rotate_l(х, 4) перемещает биты значения х на четыре позиции влево, при
этом утраченные слева биты воспроизводятся в правой части комбинации.
Другими словами, вытесненный старший бит помещается в позицию младшего
бита. Протестируйте функцию в какой-нибудь программе. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

unsigned int rotate_1(unsigned int x, unsigned int rot);
char *itobs(int, char *);
int main()
{
    unsigned int number, bitnum, ans;
    char bin_str[CHAR_BIT *sizeof(int) + 1];
    char bin_str2[CHAR_BIT *sizeof(int) + 1];
    printf("Enter the integer number and the quality of bit position to bias or enter non numeric value to exit: \n");
        while(scanf("%lu%lu", &number, &bitnum) == 2)
    {
        ans = rotate_1(number, bitnum);
        printf("%u (%s) bias for %u bits is %u (%s)", number, itobs(number, bin_str), bitnum, ans,
               itobs(ans, bin_str2));
        putchar('\n');
    }
    return 0;
}
char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for(i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0'; //ASCII intepretation
    ps[size] = '\0';
    return ps;
}
unsigned int rotate_1(unsigned int x, unsigned int rot)
{
    static const int size = CHAR_BIT * sizeof(int);
    int over;
    rot %= size; /* keep b a valid value */
    over = x >> (size - rot);  /* save bits that are shifted out */
    return ((x << rot) | over);
}
