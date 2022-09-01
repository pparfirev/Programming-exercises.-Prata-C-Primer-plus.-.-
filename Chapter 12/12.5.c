/* �������� ���������, ������� ���������� ������ �� 100 ��������� ����� �
��������� �� 1 �� 10, ��������������� �� ��������. (������ ������������
� ���� int �������� ���������� �� ����� 11, ������ � ���� ������ ����������
���� �����.) */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
static int mas[SIZE - 1];
void mas_sort(int m[]);
int main(void)
{
    int count;
    printf("Before: ");
    for(count = 0; count < SIZE; count++)
    {
        mas[count] = 1 + (rand() % 10);
        printf(" %d", mas[count]);
    }
    printf("\n");
    mas_sort(mas);
    printf("After: ");
    for(int n = 0; n < SIZE; n++)
    printf("%d ", mas[n]);
    return 0;
}
void mas_sort(int m[])
{
    int temp;
    for(int n = 0; n < SIZE - 1; n++)
    {
        for(int j = 0; j < SIZE - n - 1; j++)
        {
        if(m[j] > m[j + 1])
        {
        temp = m[j];
        m[j] = m[j + 1];
        m[j + 1] = temp;
        }
    }
    }
}
