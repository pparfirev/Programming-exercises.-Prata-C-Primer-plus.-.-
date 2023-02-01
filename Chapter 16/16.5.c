/* �������� �������, ������� � �������� ��������� ��������� ��� ������� ���������
int, ������ ������� � ��������, �������������� ���������� �������.
������� ������ ��������� ������� �������� �� ������� ��������� ����������
��������� � �������� �� ��������. �� ���� ������� ������� �� ������ ����������
����� ������ ����. (��� ��������� ����� ����� � ������� ��� ������
����.) ���� � ������ ���������� �������� ������� time() (������� �������-
���� � ����� 12) ��� �������� �� �������, �� ��� ������ ������ ��������������
�������� srand(), ����� ���������������� ��������� ��������� �����
rand(). �������� ������� ��������� ��� ������������ ���� �������. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50
void s_sort(int ar[], int size, int qual);
int main()
{
    int mas[SIZE];
    for(int i = 0; i < SIZE; i++)
        mas[i] = i;
    int sample;
    puts("Enter the number of samples in the array: (or enter q to exit)");
    while(scanf("%d", &sample) == 1)
    {
        if(sample > SIZE)
        {
            printf("Sample must be less or equal massive size (%d).\n", SIZE);
            puts("Enter the number of samples in the array: (or enter q to exit)");
            continue;
        }
        s_sort(mas, SIZE, sample);
        puts("Enter the number of samples in the array: (or enter q to exit)");
    }
    return 0;
}
s_sort(int ar[], int size, int qual)
{
    int index, temp;
    for(int i = 0; i < qual; i++)
    {
        srand(time);
        index = rand() % (size - 1); // Pick a random element
        printf("%d ",  ar[index]); // Display
        if(i % 10 == 0 || i == qual - 1)
            putchar('\n');
    }
}

