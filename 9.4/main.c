#include <stdio.h>
#include <stdlib.h>
/* 4. ������� ������������� �������� ���� ����� ���������� ����� ��������������
���� �����, ���������� �������� �������� �������� � ��������� �������� ����������.
�������� �������, ������� ��������� ��� ��������� double � ����������
������� ������������� �������� ���� ���� �����. */
double harm(double x, double y);
int main()
{
    double a1, a2;
    double ans;
    printf("Enter 2 float numbers or press q to exit: (wrong enter will close the progam)\n");
    while(scanf("%lf%lf", &a1, &a2) == 2)
    {
        ans = harm(a1, a2);
        printf("Harmonic mean of 2 numbers is %0.3lf\n", ans);
        printf("Enter 2 float numbers or press q to exit: \n");
    }
    printf("Program Closed.\n");
    return 0;
}
double harm(double x, double y)
{
    return (2 / ((1 / x) + (1 / y)));
}
