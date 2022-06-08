#include <stdio.h>
#include <stdlib.h>
#define f_sm 30.48
#define IN_SM 2.54
#define foot_inch 12

/* �������� ���������, ������� ����������� � ������������ ���� �������� ������
� �����������, ����� ���� ���������� ������ � �����������, � ����� � ��-
� ������. ������ ���� ��������� ������� ����� ����������� � ������.
��������� ������ ��������� ������������ ���������� ���� �������� ������
�� ��� ���, ���� �� ����� ������� ��������������� ��������. ����� ���� ���������
������ ����� ��������� ���:
������� ������ � �����������: 182
182.� �� = 5 �����, 11.7 ������
������� ������ � ����������� (<=� ��� ������ �� ���������) : 168.7
168.0 �� = 5 �����, 6.4 ������
������� ������ � ����������� (<=� ��� ������ �� ���������) : 0
������ ���������. */

int main()
{
    float en_sm, inch;
    int foot;
    printf("Enter length in sm (<=0 for leave the program)\n");
    scanf("%f", &en_sm);
    while(en_sm >= 0)
    {
        foot = en_sm / f_sm;
        inch = (fmod(en_sm, f_sm)) / IN_SM;
        printf("%.1f = %d foots, %.1f inches\n", en_sm, foot, inch);
        printf("Enter the new length in sm (<=0 for leave the program)\n");
        scanf("%f", &en_sm);
    }
    printf("Program is ended\n");
    return 0;
}
