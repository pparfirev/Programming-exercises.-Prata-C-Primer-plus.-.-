#include <stdio.h>
#include <stdlib.h>
/* 4.1 �������� ���������, ������� ����������� ��� � �������, � ����� ������� ��
� ������� �������, ���. */

int main()
{
    char name[30], surname[50];
    printf("Enter you Name\n");
    scanf("%s", name);
    printf("Enter you Surname\n");
    scanf("%s", surname);
    printf("%s, %s", surname, name);
    return 0;
}
