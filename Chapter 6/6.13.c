#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* �������� ���������, ������� ������� ���������������� ������ ���� int � ��������
� ���� �������� ��������� ������ �������� 2, � ����� ������� ����������
��������. ���������� ���� for ��� ���������� ��������� �������, � ����
������������ ��� ����������� �������� �������������� ������ do while. */
int main()
{
    int mas[8];
    int step = 0, n;
    for(n = 0; n < 8; n++)
    {
        mas[n] = pow(2, n); // ������� ���������� � �������
    }
   while(step < 8) // ���� ������ ��������� �������
   {
       printf("%d ", mas[step]);
       step++;
   }
  //  printf("%d %d %d %d %d %d %d %d", mas[0], mas[1], mas[2], mas[3], mas[4], mas[5], mas[6], mas[7], mas[8]); // ��������
    return 0;
}