/* �������� �������, ������� ������������� �������� ������� �������� �������
� ����� ��������������� ��������� � ���� ������ ��������. ������� �������,
���� ������ 1 ����� �������� 2, 4, 5 � 8, � ������ 2 � �������� 1, 0, 4 � 6, �� ���
������� ����������� ������� 3 �������� 3, 4, 9 � 14. ������� ������ ���������
� �������� ���������� ����� ���� �������� � �� �������. �������������
��� ������� � ������� ������� ���������. */
#include <stdio.h>
#include <stdlib.h>
void mas_sum(int n, int first[n], int sec[n], int sum[n]); // ���������� ������� ������������ ��������
void view_mas(int n, int mas[n]); // ���������� ������� ����������� ��������
int main()
{
    int mas1[4] = {2,4,5,8};
    int mas2[4] = {1,0,4,6};
    int mas_s[4];
    printf("mas_s before = { ");
    view_mas(4, mas_s);
    mas_sum(4, mas1, mas2, mas_s);
    printf("mas_s after = { ");
    view_mas(4, mas_s);
    return 0;
}
void view_mas(int n, int mas[n])
{
    for(int count = 0; count < n; count++)
        printf("%d ", mas[count]);
    printf("};\n");
}
void mas_sum(int n, int first[n], int sec[n], int sum[n])
{
    for(int count = 0; count < n; count++)
        sum[count] = first[count] + sec[count]; // �������� ��������� 2-�� �������� � ������������ ��������
    return;
}
