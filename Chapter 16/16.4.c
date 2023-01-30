/* ���������� ANSI �������� ������� clock () �� ��������� ���������:

#include <time.h>
clock_t clock (void);

����� clock_t � ��� ������, ������������ � ����� time.h. ������� ����������
������������ �����, ���������� � ��������, ������� ������� �� ����������.
(���� ������������ ����� ���������� ��� �� ����� ���� ������������,
������� ���������� -1.) ������ � ����� time.h ����� ���������� ���������
CLOCKS_PER_SEC, ������� ������������ ���������� ������ ������������� �������
� �������. �������������, � ���������� ������� ������� ����� ����� ����������,
������������� clock(), �� ��������� CLOCKS_PER_SEC ����������
���������� ������, ��������� ����� ����� �������� �������. ����������
�������� � ���� double �� �������� ������� �������� �������� ��������� �
����� �������. �������� �������, ������� ��������� �������� ���� double,
�������������� ���������� �������, � ����� ��������� ���� �� ���������
���������� ������� �������. �������� ������� ��������� ��� ������������
���� �������. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t clock(void);
void interval(double);

int main()
{
    double time_c;
    printf("Enter the choose time delay in seconds: ");
    scanf("%lf", &time_c);
    clock_t start, stop;
    start = clock(); // Time starting
    interval(time_c); // Delay function
    stop = clock();
    printf("The delay is %.2lf second.\n", ((double) stop - start) / CLOCKS_PER_SEC);
    return 0;
}
void interval(double t)
{
    clock_t begin, end;
    begin = clock(); // starting time
    do
    {
        end = clock(); // ending time
    }while(((double)end - begin) / CLOCKS_PER_SEC < t); // Cycle is going until time is less that entering delay t
}
