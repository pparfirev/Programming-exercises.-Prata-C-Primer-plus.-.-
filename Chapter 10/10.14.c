/* ��������� ���������� 13, �� ����������� � �������� ���������� ������� �������
���������� �����. */
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3 // ������� ������� ������� ���������
#define COLS 5
void mas_v(int x, int y, double view[x][y]); // ���������� ������� ����������� �������
void mas_mid(int y, double view[][y], int x); // ������� �������� ������ �������
double mid_t(int x, int y, double mid[x][y]);  // ������� �������� ���� ��������� �������
double max_el(int x, int y, double mid[x][y]); // ����� ������������� �������� �������
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
    mas_v(ROWS, COLS, mas);
    for(int rows = 0; rows < ROWS; rows++) // ������� �������� ��� ������� ������ �� ���� �������� ������������� ����� ����
        mas_mid(COLS, mas, rows);
    double mid_value = mid_t(ROWS, COLS, mas);
    printf("Middle value of all elements of massive %.2lf\n", mid_value);
    double max = max_el(ROWS, COLS, mas);
    printf("Max value of all massive's elements is %.2lf\n", max);
    return 0;
}
void mas_v(int x, int y, double view[x][y]) // ����������� �������
{
    for(int x_count = 0; x_count < x; x_count++) // ����� ��� ����������� ��������� ��������
    {
        printf("\n");
         for(int y_count = 0; y_count < y; y_count++)
            printf(" %.2lf ", view[x_count][y_count]);
    }
    printf("};\n");
}
void mas_mid(int y, double view[][y], int x)
{
    double mid = 0, sum = 0;
    for(int i = 0; i < y; i++)
     sum += view[x][i]; // ����� ���� ��������� ������
    mid = sum / y; // ������ �������� ��������
    printf("The mid value of row %d is %.2lf\n", x, mid);
    return mid;
}
double mid_t(int x, int y, double mid[x][y])
{
    double midle = 0, sum = 0;
    for(int x_count = 0; x_count < x; x_count++)
    {
    for(int i = 0; i < y; i++)
        sum += mid[x_count][i]; // ����� ���� ��������� �������
     midle = sum / (x * y); // ������ �������� ���������������
    }
    return midle;
}
double max_el(int x, int y, double mid[x][y])
{
    double high_n = mid[0][0]; // ��������� �������� ������������� �������� [0][0]
    for(int x_count = 0; x_count < x; x_count++)
    {
    for(int y_count = 0; y_count < y; y_count++)
    {
        if(mid[x_count][y_count] >= high_n) // ������������ ��������� ��������. ���� ��������� ������, "�������� �����������"
            high_n = mid[x_count][y_count]; // �� ������������� ����� ���������� ��������
    }
    }
    return high_n;
}
