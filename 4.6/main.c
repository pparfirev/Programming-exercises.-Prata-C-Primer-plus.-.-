#include <stdio.h>
#include <stdlib.h>
/*�������� ���������, ������� ����������� ��� ������������ � ��� �������.
�������� ���, ����� ��� �������� ��������� ����� � ����� ������ � ����������
�������� � ������ ����� � ��������� ������. ���������� ������ ����������
�������� �� ��������� ���������������� �����, ��� �������� ����:
���� ������
   4      6
����� �������� ���, ����� ��������� �������� �� �� ����� ����������, �� �
����������� ��������, ����������� �� ������ ������� �����:
���� ������
4    6     */
int main()
{
    char name[30], surname[30];
    printf("Enter your name:\n");
    scanf("%s", name);
    printf("Enter your surname:\n");
    scanf("%s", surname);
    printf("%s %s\n%*d %*d\n", name, surname, strlen(name), strlen(name), strlen(surname), strlen(surname));
    printf("%s %s\n%-*d %-*d", name, surname, strlen(name), strlen(name), strlen(surname), strlen(surname));
    return 0;
}
