/* �������� ������� �� ����� transform(), ������� ��������� ������ ���������:
��� ��������� �������, ����������� ������ ���� double, ��� ��������
������� ���� double, �������� int, �������������� ���������� ��������� �������,
� ��� ������� (���, ��� ������������, ��������� �� �������). �������
transform() ������ ��������� ��������� ������� � ������� �������� ���������
������� � �������� ������������ �� �������� � ������� ������.
��������, �����
transform(source, target, 100, sin);
������ ���������� target[0] � sin(source[0]) � ������� �� �� ����� ��� 100
��������� �������. ������������� ������� � ���������, ������� ��������
transform() ������ ����, ��������� � �������� ���������� ��� ������� �� ����������
math.h � ��� ���������� �������, ������� �������� ���� ����������
��� transform(). */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void transform(double source[], double *target, int n, double func(double));
double Discount50(double);
double Pow2(double);
int main()
{
    double orig[5] = {1.23, 4.14, 5.56, 7.89, 14.55};
    double neu[5];
    printf("Original: ");
    for(int n = 0; n < 5; n++)
        printf("%.3lf  ", orig[n]);
    printf("\n");
    transform(orig, neu, 5, sqrt);
    printf("Sqrt: ");
    for(int n = 0; n < 5; n++)
        printf("%.3lf ", neu[n]);
    printf("\n");
    printf("Cbrt: ");
    transform(orig, neu, 5, cbrt);
    for(int n = 0; n < 5; n++)
        printf("%.3lf ", neu[n]);
    printf("\n");
    printf("50%% off: ");
    transform(orig, neu, 5, Discount50);
    for(int n = 0; n < 5; n++)
        printf("%.3lf ", neu[n]);
    printf("\n");
    printf("50%% off: ");
    transform(orig, neu, 5, Pow2);
    for(int n = 0; n < 5; n++)
        printf("%.3lf ", neu[n]);
    printf("\n");
    return 0;
}
void transform(double source[], double *target, int n, double func(doube))
{
    for(int x = 0; x < n; x++)
        *(target + x) = func(source[x]);
}
double Discount50(double n)
{
    return n * 0.5;
}
double Pow2(double n)
{
    return n * n;
}
