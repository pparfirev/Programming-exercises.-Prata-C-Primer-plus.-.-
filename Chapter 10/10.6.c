/* 6. �������� �������, ������� �������� ������� ���������� ����������� �������
�������� ���� double �� ��������������� � ������������� �� � �������
���������. */
#include <stdio.h>
#include <stdlib.h>
void reverse(double mas[], int n);
int main()
{
    double mas[] = {-13.45, -45.45, -248.26, -654.36, 9448.34, -10.74};
    int count = 0;
    printf("Before mas[] = {");
    while(count < 6)
    {
        printf(" %1.2f ", mas[count]);
        count++;
    }
    printf("}\n");
    reverse(mas, 6);
    count = 0;
    printf("After mas[] = {");
    while(count < 6)
    {
        printf(" %1.2f ", mas[count]);
        count++;
    }
    printf("}\n");
    return 0;
}

void reverse(double mas[], int n) // ������� �� ����������� �������� �������� � �������� �������
{
    int rev = n - 1;
    double mas_t[n]; // �������� ���������� ������� ��� ��������� � ���� ��������� � �������� �������
    for(int count = 0; count < n; count++, rev--)
        *(mas_t + count) = mas[rev];
        for(int count = 0; count < n; count++, mas++) // ����������� ��������� �� ���������� ������� � ��������
        *mas = mas_t[count];
    return 0;
}
