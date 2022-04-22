#include <stdio.h>
#include <stdlib.h>
/* Напишите программу, которая читает восемь целых чисел в массив, после чего
выводит их в обратном порядке. */
int main()
{
    int mas[8];
    printf("Enter 8 int. numbers: ");
    scanf("%d %d %d %d %d %d %d %d", &mas[0], &mas[1], &mas[2], &mas[3], &mas[4], &mas[5], &mas[6], &mas[7]);
    printf("%d %d %d %d %d %d %d %d", mas[7], mas[6], mas[5], mas[4], mas[3], mas[2], mas[1], mas[0]);
    return 0;
}
