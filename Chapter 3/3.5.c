#include <stdio.h>
#include <stdlib.h>
/* � ���� ���������� �������� 3.156�10^7 ������. �������� ���������, �������
���������� ������ ������� � �����, � ����� ������� �� ����� ������������� ��������
� ��������. */
int main()
{
    int age;
    float yins = 3.156e+7;
    printf("Enter your age in years:");
    scanf("%d", &age);
    float ageins = age * yins;
    printf("Ypur age in seconds is: %e", ageins);
    return 0;
}
