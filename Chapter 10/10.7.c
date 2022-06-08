/* �������� ���������, ������� �������������� ��������� ������ ��������
���� double � ���������� ���� �� ������� ����������� �� ���������� 2 ���
��� ����������� �� ������ ��������� ������. (��������� ��������� ������ -
��� ������ ��������, ������� ��� ����������� ���������� �������� �����
���������� � ������ �����������.) */
#include <stdio.h>
#include <stdlib.h>
void copy_arr(double copy[][5], double origin[][5], int n);
int main()
{
    double source[2][5] = {{1.1,2.2,3.3,4.4,5.5}, {6.6,3.7,8.8,9.9,10.0}};
    double copy[2][5];
    int x_count = 0;
    int y_count = 0;
    printf("Before source = {");
    for(int x_count = 0; x_count < 2; x_count++) // ����� ��� ����������� ��������� �������� (��������)
    {
        printf("\n");
         for(int y_count = 0; y_count < 5; y_count++)
            printf(" %1.1f ", source[x_count][y_count]);
    }
    printf("};\n");
    printf("Before copy = {");
    for(int x_count = 0; x_count < 2; x_count++) // ���������� ��
    {
        printf("\n");
         for(int y_count = 0; y_count < 5; y_count++)
            printf(" %1.1f ", copy[x_count][y_count]);
    }
    printf("};\n");
    copy_arr(copy, source, 2);
    printf("After copy = {");
     for(int x_count = 0; x_count < 2; x_count++) // ���������� �����
    {
        printf("\n");
         for(int y_count = 0; y_count < 5; y_count++)
            printf(" %1.1f ", copy[x_count][y_count]);
    }
    printf("};\n");

    return 0;
}
void copy_arr(double copy[][5], double origin[][5], int n)
{
    int count_x = 0;
    int count_y = 0;
    for(count_x = 0; count_x < n; count_x++) // ���� ������������� �����������
    {
        for(count_y = 0; count_y < 5; count_y++)
            copy[count_x][count_y] = origin[count_x][count_y];
    }
    return;
}
