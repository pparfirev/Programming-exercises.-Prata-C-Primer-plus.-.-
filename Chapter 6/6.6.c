#include <stdio.h>
#include <stdlib.h>
/* �������� ��������� ��� ������ �������, � ������ ������ ������� ������������
����� �����, ��� ������� � ��� ���. ��������� � ������������ ������� �
������ ������� �������. ����������� ���� for. */

int main()
{
    int n1, n2, n; // n ���������� �����
    printf("Enter the first number of table: "); // ���� ���������� �������� ��������� �����
    scanf("%d", &n1);
    printf("Enter the last number of table: ");
    scanf("%d", &n2);
        for (n = 0; n < n2, n1 <= n2; ++n1, n++) // ���� ����������� �� ��� ��� ���� ���������� ����� ������ n2, � �������� n1 �� ������ ������ ��� ������� n2
        printf("%d, %d, %d\n", n1, n1 * n1, n1 * n1 * n1); //����� ����� ��� �������� � ����
    return 0;
}
