#include <stdio.h>
#include <stdlib.h>
/* �������� ���������, ������� ��������� ����� � ��������� ������� � �������
��� ������� � ���������� �������������, ����� � ���������������� �������������
� ����� � �������-���������������� �������������, ���� ������� ��� ������������.
����� ������ ���� ����������� � ��������� ������� (�����������
���������� ������������ ���� ���������� ������� ������� �� �������): */

int main()
{
    float number;
    printf("Enter the float number: ");
    scanf("%f", &number);
    printf("Dex is:%f\nExp is %e\nBin-exp: %a\n", number, number, number);

    return 0;
}
