/* �������� ��������� ���������� ��������� �����������, ������� �������� ��
������ ��������� ������. ������ ���������� ��������� ������ ������ ����
����� ���� double , ���������� � ������������ �������, � ������ ���������� -
������������� ���������� �������. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double num = atof(argv[1]);
    int exp = atoi(argv[2]);
    printf("%lf of the power of %d is equal %lf!\n", num, exp, pow(num, exp));
    return 0;
}
