#include <stdio.h>
#include <stdlib.h>
#define dw 7
/* �������� ���������, ������� ����������� � ������������ ���� ����������
���� � ����� ����������� ��� �������� � ���������� ������ � ����. ��������,
18 ���� ��������� ������ ������������� � 2 ������ � 4 ���. ����������� ����������
� ��������� �������:
18 ���� ���������� 2 ������ � 4 ���.
����� ������������ ��� ����������� ������� ���������� ����, �����������
���� while. ���� ������ ����������� ��� ����� ������������� ����������������
��������, ��������, � ��� -20. */

int main()
{
    int days, weeks, en_days;
    printf("Enter number of days\n");
    scanf("%d", &en_days);
    while(en_days > 0)
    {
    weeks = en_days / dw;
    days = en_days % dw;
    printf("%d days is %d weeks and %d days\n", en_days, weeks, days);
    printf("Enter number of days\n");
    scanf("%d", &en_days);
    }
    printf("Calculation is over.\n");
    return 0;
}
