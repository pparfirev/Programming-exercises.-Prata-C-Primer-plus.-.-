#include <stdio.h>
#include <stdlib.h>
/* � ������������ ������� ������ ��������� ������ ����� ����� 2 ������, �����
� 8 ������, ����� � 2 �������� ������, � �������� ����� � 3 ������ ������.
�������� ���������. ������� ���������� ������ ����� � ������ � ����-
����� ������������� �������� � ������, ������, �������� ������ � ������
������. ������ ��� ���� ��������� ��� � ��������� ������� �������� ������,
��� �������������? */

int main()
{
    float pints, cups, ounce, b_spoon, lil_spoon;
    printf("Enter the volume in cups:");
    scanf("%f", &cups);
    pints = cups / 2;
    ounce = cups * 8;
    b_spoon = ounce * 2;
    lil_spoon = b_spoon * 3;
    printf("In %f cups %f pints, %f ounces, %f tablespoons, %f tea spoons\n", cups, pints, ounce, b_spoon, lil_spoon);
    return 0;
}
