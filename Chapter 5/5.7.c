#include <stdio.h>
#include <stdlib.h>
/* �������� ���������, ������� ����������� ���� ����� ���� double � �������
�������� ���� ����� �����. ��� ����� ����������� ����������� �������,
������� �������� �������� � ��� � ������� ���������� ���������. ���������
main () ������ ���������� ���� ������� �������� ��������. */

void coub(float n)
{
   n = n * n * n;
   printf("Coub is %.2f\n", n);
}

int main()
{
    float num;
    printf("Enter the numer\n");
    scanf("%f", &num);
    coub(num);
    return 0;
}
