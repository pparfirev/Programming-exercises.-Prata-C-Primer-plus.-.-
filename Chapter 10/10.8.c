/* �������������� ����� �� ������� ����������� �� ���������� 2 ��� �����������
��������� � 3-�� �� 5-� ��������������� ������� � ������, ��������� ��
���� ���������. ���� ������� �������� �� �����; ������ ��������� ����������
����������� ���������. (������������ ����������� �� ����������� ������
���� ��� ������� � ��� ������. ��� ������ ������ ���� ����� ��������
������� � ���������� �������������� ���������.) */
#include <stdio.h>
#include <stdlib.h>
void copy_ptr(double *copy, double *origin, int n);
int main()
{
    double source[7] = {1.1,2.2,5.3,4.4,5.5,6.6,7.7}; // �������� �������������� ������
    double copy[3];
    printf("Source = {");
    for(int count = 0; count < 7; count++)
        printf(" %1.1f ", source[count]);
    printf("}\n");
    printf("Before copy = {");
    for(int count = 0; count < 3; count++)
        printf(" %1.1f ", copy[count]);
    printf("}\n");
    copy_ptr(copy, (source + 2), 3); // � ������� ������������ �������� ������ ������� � ������ �������� �������� (3,3)
    printf("After copy = {");
    for(int count = 0; count < 3; count++)
        printf(" %1.1f ", copy[count]);
    printf("}\n");

    return 0;
}
void copy_ptr(double *copy, double *origin, int n) // ������� ����������� ��������, ����� �� ��� � � ���������� 10,2
{
    for(int count = 0; count < n; count++, copy++, origin++)
    {
        *copy = *origin;
    }
    return;
}
