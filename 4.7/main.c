#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/* �������� ���������, ������� ����������� ���������� ���� double ��������
1.0/3.0 � ���������� ���� float �������� 1.0/3.0. ���������� ������ ���������
��� ����: � ������ ������ � �������� ������� ������ �� ���������� �����,
�� ������ ������ � ����������� ������� � � ������� ������ � ������������
�������. �������� ����� � ��������� ������������ ���� float.h � ��������
�������� FLT_DIG � DBL_DIG. ����������� �� ���������� �������� �� ���������
1.0/0.3? */
int main()
{
    double n_d;
    float n_f;
    n_d = 1.0 / 3.0;
    n_f = 1.0 / 3.0;
    printf("Result 4: double - %.4f, float -  %.4f\n", n_d, n_f);
    printf("Result 12: double - %.12f, float -  %.12f\n", n_d, n_f);
    printf("Result 16: double - %.16f, float -  %.16f\n", n_d, n_f);
    printf("Double - %d Float - %d", DBL_DIG, FLT_DIG);
    return 0;
}
