/* �������� ���������, ������� ��������� ������ 3�5 �������� ���� int � ��������������
��� ���������� �� ������ ������. ��������� ������ ������� ���
��������, ������� ��� ��������, ����� ���� ������� ����� ��������. ��������
���� ������� ��� ������ �������� � ��� ���� ��� ���������� ��������. � ��������
���������� ������� ������ ��������� ��� ������� � ����������
�����. */
#include <stdio.h>
#include <stdlib.h>
#define COLS 5
void mult_mas(int n, int mas[n][COLS]); // ���������� ������� �������� ��������� �������
void mas_v(int n, int mas[n][COLS]); // ���������� ������� ����������� �������
int main()
{
    int source[3][COLS] = {{1,2,3,4,5},
                          {5,4,3,2,1},
                          {6,7,8,9,0}};
    printf("Before sourse[] = {");
    mas_v(3, source);
    mult_mas(3, source);
    printf("After sourse[] = {");
    mas_v(3, source);
    return 0;
}
void mas_v(int n, int mas[n][COLS]) // ����������� �������
{
    for(int x_count = 0; x_count < n; x_count++) // ����� ��� ����������� ��������� ��������
    {
        printf("\n");
         for(int y_count = 0; y_count < COLS; y_count++)
            printf(" %d ", mas[x_count][y_count]);
    }
    printf("};\n");
}
void mult_mas(int n, int mas[n][COLS]) // �������� ��������� �������
{
    for(int count_x = 0; count_x < n; count_x++) // ���� ������������� ���������
    {
        for(int count_y = 0; count_y < COLS; count_y++)
            mas[count_x][count_y] *= 2;
    }
    return;
}
