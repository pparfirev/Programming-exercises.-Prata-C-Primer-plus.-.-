#include <stdio.h>
#include <stdlib.h>
#define MIN_H 60

/* �������� ���������, ������� ����������� ����� � ������� � ���� � ������.
��� �������� 60 �������� ������������� �������� ����������� #define ���
const. ����������� ���� while, ����� ���������� ������������ �����������
���������� ����� �������� � ��� ����������� �����, ���� �������� ��������
�������, ������� ��� ������ ����. */

int main()
{
    int hours, ent_minutes, minutes;
    printf("Enter time in minutes\nIf you enter zero minutes or negative value program will shut down\n");
    scanf("%d", &ent_minutes);
    while(ent_minutes > 0)
    {
        hours = ent_minutes / MIN_H;
        minutes = ent_minutes % MIN_H;
        printf("In %d minutes - %d hours and %d minutes\n", ent_minutes, hours, minutes);
        printf("Enter new  time in minutes\nIf you enter zero minutes or negative value program will shut down\n");
        scanf("%d", &ent_minutes);
    }
    printf("Program closed\n");
    return 0;
}
