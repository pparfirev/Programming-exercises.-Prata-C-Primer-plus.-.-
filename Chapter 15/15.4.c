/* �������� �������, ������� ��������� ��� ��������� ���� int: �������� � ����-
��� ����. ������� ������ ���������� 1, ���� ��� � ���� ������� ����� 1, � 0
� ��������� ������. ������������� ������� � �����-������ ���������. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int bitpos(int n, int pos);
char *itobs(int, char *);
int main()
{
    int number, bitnum;
    char bin_str[CHAR_BIT *sizeof(int) + 1];

    printf("Enter the integer number and bit position to analyze or enter non numeric value to exit: \n");
        while(scanf("%d %d", &number, &bitnum) == 2)
    {
        printf("%d (%s) has %d value at the bit %d", number, itobs(number, bin_str), bitpos(number, bitnum), bitnum);
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
int bitpos(int n, int pos)
{
    static const int size = CHAR_BIT * sizeof(int);
    int ans;
    int i;
        for(i = 0; i < size; i++, n >>= 1)
    {
        if(i == pos && (1 & n) == 1) // Bitwise AND for counting enabled bits in number
            return 1;
        if(i == pos && (1 & n) == 0)
            return 0;
    }
    return NULL;
}
