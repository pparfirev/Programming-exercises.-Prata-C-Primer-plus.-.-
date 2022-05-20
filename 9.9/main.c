#include <stdio.h>
#include <stdlib.h>
/* 9. ��� ��� ��������� ���������� 8, �� �� ���� ��� ����������� �����������
�������. */
double power(double n, int p);

int main()
{
    double x, xpow;
    int exp;
    printf("Enter the number and positive int exp.\nFor exit the program enter 'q'\n");
    while(scanf("%lf%d", &x, &exp) == 2) // ��������� ��� ��������� ����� (�������� � ��� �������) ������� ���������� 2 ����� ��� ����� ������� �����
    {
        xpow = power(x, exp); // ����� �������
        if(xpow == 1 && x == 0 && exp == 0)
            printf("this is incorrect answer, because 0 to the power of 0 is not determined.\n"); // ��������� ��� ����, ��� ���������� ������� ������� ��� 0^0
        printf("%.3g to the power of %d is %0.5lf\n", x, exp, xpow);
        printf("Enter the next number and positive int exp.\nFor exit the program enter 'q'\n");
    }
    return 0;
}

double power(double n, int p) //�������� ANSI
{
    double pow = 1, m_pow = 1;
    int i;
    if(n == 0 && p == 0) // ���� ����� � ��� ������� ������� 0
        pow = 1;
    else if(p > 0)
    {
    for (i = 1; i <= p; i++)
        pow = n * power(n, p - 1); // ����������� �������
    }
    else if(p < 0) // ���� ������� �������������
        for(i = -1; i >= p; i--) // �� ������������ �������� ������ � �����
        {
        m_pow = n * (n, p); // �������������� ���������� ����� ���������� ������������� ������� (� ���������)
        pow = 1 / m_pow;
        }
    else
        pow = 1;
    return pow; // ���������� �������� pow (������� ���������� ��������� � ���� ���������� pow)
}
