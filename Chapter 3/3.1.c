#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
/* ����������������� ����� ��������, ��� ���� ������� ������������ ������������
��� ���������� �������� ��� ������ ������� � ��� ������� � ���������
�������, � ����� ������ ���������� ��� ���������� �������� ��� �������
� ��������� �������; �.�. �������� ���������, � ������� ������������
����� ��������. (��� ��������� �������� � ���������� � ���������� ���������
����������� ���������� limits.h � float.h � ����� 4.) */

int main()
{
    printf("Max value of int is %d \n", INT_MAX);
    int int_overflow = INT_MAX + 1;
    printf("Int overflow is %d \n", int_overflow);
    printf("Max value of float is %f \n", FLT_MAX);
    float float_overflow = FLT_MAX +500000;
    printf("Float overflow is %f \n", float_overflow);
    float n1 = 2.74;
    float n2 = 3.56;
    int sum = n1 + n2;
    printf("Wrong summary is %d \n", sum);
    return 0;
}
