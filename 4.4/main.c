#include <stdio.h>
#include <stdlib.h>
/* �������� ���������, ������� ����������� ���� � ������� ���, ����� ����
���������� ���������� ���������� � ��������� �����:
�����, ��� ���� ���������� 6.208 �����
����������� ��� float, � ����� �������� ������� /. ���� ������, ������ �����������
���� � ����������� � ���������� ��� � ������. */
int main()
{
    char name[30];
    float len, len_m;
    printf("Please, enter your name\n");
    scanf("%s", name);
    printf("Enter your lenght in cm:");
    scanf("%f", &len);
    len_m = len / 100;
    printf("Ok, %s. Your length if metres is %.2af", name, len_m);
    return 0;
}
