#include <stdio.h>
#include <stdlib.h>
/* �������� � ������������� ������� �� ����� larger_of() , ������� ��������
���������� ���� ���������� double ������� �� �� ��������. ��������, �����
larger_of (�, �) �������� ���������� � � � ������� �� �� ��������. */
void larger_of(double *a, double *b);
int main()
{
    double x, y;
    printf("Enter 2 float numbers or press q to exit: (wrong enter will close the progamm)\n");
    while(scanf("%lf%lf", &x, &y) == 2)
    {
     printf("x = %0.2lf and y = %0.2lf\n", x, y);
     larger_of(&x, &y);
     printf("Now x = %0.2lf and y = %0.2lf\n", x, y);
    }
    printf("Program closed.\n");
    return 0;
}
void larger_of(double *a, double *b)
{
    if(*a > *b)
        *b = *a;
    else
        *a = *b;
}
