#include <stdio.h>
#include <stdlib.h>
/* 3. �������� �������, ������� ��������� ��� ���������: ������ � ��� ����� �����.
������ ������������ ��� ������. ������ ����� �������� ������ ����������
��������� �������� � ������, � ������ ����� ����� ������������� ����������
����� �����. �������� ���������, � ������� ������������ ��� �������. */
void ch_func(char ch, int x, int y);
int main()
{
    char symb;
    int a, b;
    printf("Enter the symb: \n");
    symb = getchar();
    printf("Enter the quantity symbol in row and quantity of cols\n");
    scanf("%d%d", &a, &b);
    ch_func(symb, a, b);
    return 0;
}
void ch_func(char ch, int x, int y)
{
    int count;
    int n;
    for(count = 0; count < y; count++)
    {
      //putchar(ch);
        for(n = 0; n < x; n++)
            putchar(ch);
            putchar('\n');
    }
    return;
}
