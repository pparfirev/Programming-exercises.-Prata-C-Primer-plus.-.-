#include <stdio.h>
#include <stdlib.h>
/* � ����� ������� 2.54 ����������. �������� ���������, ������� ����������
������ ���� � ������, ����� ���� ������� �� ����� ���� ���� � �����������.
����, ���� ��� ��� ������ ��������, ��������� ����� ����������� ���� � �����������
� ���������� ��� � �����. */
int main()
{
    float inch = 2.54;
    float length;
    printf("Enter length in santimetres:");
    scanf("%f", &length);
    float len_inch = length / inch;
    printf("In %f santimetres is %f inches", length, len_inch);

    return 0;
}
