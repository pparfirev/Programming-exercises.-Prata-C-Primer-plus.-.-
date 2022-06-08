/* �������� ���������, ������� ���������� ������������ ������ ��� ������ ��
���� ����� double. (��� �������� ������ ��������, ��� ������������ ��������
��������� � �� ������ ���������� ������.) ��������� ������ ��������� ���
������������� ���� ��������.
�. ������� ���������� � ������� 3�5.
�. ��������� ������� ��� ������� ������ �� ���� ��������.
�. ��������� ������� ��� ���� ��������.
�. ���������� ���������� �� 15 ��������.
�. �������� ���������� �� �����.
������ ������������ ������ ������ �������� ����������� ��������� �������
� �������������� ������������� � ����� � ������� � ��������� ��������. ���������
������ �) � ������� �������, ������� ��������� � ���������� �������
�������� ����������� �������; �������������� ������ ��� ������ ���� �������
��� ����. �������, ����������� ��������� ������, ������ ��������� �
�������� ��������� ������ �������, � �������, ����������� ������ �) � �),
������ ���������� ����� � ���������� ���������. */
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3 // ������� ������� ������� ���������
#define COLS 5
void mas_v(double view[ROWS][COLS]); // ���������� ������� ����������� �������
void mas_mid(double view[][COLS], int x); // ������� �������� ������ �������
double mid_t(double mid[ROWS][COLS]);  // ������� �������� ���� ��������� �������
double max_el(double mid[ROWS][COLS]); // ����� ������������� �������� �������
int main()
{
    double mas[ROWS][COLS];
    printf("Enter the 1-st pack of 5 double numbers: "); // ���� ������ ������ ������� �������������� �� �������
    for(int i = 0; i < COLS; i++)
        scanf("%lf", &mas[0][i]);
    printf("Enter the 2-st pack of 5 double numbers: ");
    for(int i = 0; i < COLS; i++)
        scanf("%lf", &mas[1][i]);
    printf("Enter the 3-rd pack of 5 double numbers: ");
    for(int i = 0; i < COLS; i++)
        scanf("%lf", &mas[2][i]);
    printf("Your massive is mas[] = {"); // ��� ����������� ������������ ����� ���������� �������
    mas_v(mas);
    for(int rows = 0; rows < ROWS; rows++) // ������� �������� ��� ������� ������ �� ���� �������� ������������� ����� ����
        mas_mid(mas, rows);
    double mid_value = mid_t(mas);
    printf("Middle value of all elements of massive %.2lf\n", mid_value);
    double max = max_el(mas);
    printf("Max value of all massive's elements is %.2lf\n", max);
    return 0;
}
void mas_v(double view[ROWS][COLS]) // ����������� �������
{
    for(int x_count = 0; x_count < ROWS; x_count++) // ����� ��� ����������� ��������� ��������
    {
        printf("\n");
         for(int y_count = 0; y_count < COLS; y_count++)
            printf(" %.2lf ", view[x_count][y_count]);
    }
    printf("};\n");
}
void mas_mid(double view[][COLS], int x)
{
    double mid = 0, sum = 0;
    for(int i = 0; i < COLS; i++)
     sum += view[x][i]; // ����� ���� ��������� ������
    mid = sum / COLS; // ������ �������� ��������
    printf("The mid value of row %d is %.2lf\n", x, mid);
    return mid;
}
double mid_t(double mid[ROWS][COLS])
{
    double midle = 0, sum = 0;
    for(int x = 0; x < ROWS; x++)
    {
    for(int i = 0; i < COLS; i++)
        sum += mid[x][i]; // ����� ���� ��������� �������
     midle = sum / (ROWS * COLS); // ������ �������� ���������������
    }
    return midle;
}
double max_el(double mid[ROWS][COLS])
{
    double high_n = mid[0][0]; // ��������� �������� ������������� �������� [0][0]
    for(int x = 0; x < ROWS; x++)
    {
    for(int y = 0; y < COLS; y++)
    {
        if(mid[x][y] >= high_n) // ������������ ��������� ��������. ���� ��������� ������, "�������� �����������"
            high_n = mid[x][y]; // �� ������������� ����� ���������� ��������
    }
    }
    return high_n;
}
