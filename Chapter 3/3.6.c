#include <stdio.h>
#include <stdlib.h>
/* ����� ����� �������� ���� �������������� ���������� 3.��10^-23 �����. ������
���� ����� �������� 950 �����. �������� ���������, ������� ���������� ������
�������� ������ ���� � ������� � ���������� ���������� ������� ���� �
���� ������. */
int main()
{
    float mol = 3.0e-23;
    int quart = 950;
    printf("Enter water volume in quarts:");
    int water;
    scanf("%d", &water);
    double qual_w = water * quart / mol;
    printf("Quality molecules in volume is: %e", qual_w);
    return 0;
}
