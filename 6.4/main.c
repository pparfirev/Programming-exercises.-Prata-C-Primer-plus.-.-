#include <stdio.h>
#include <stdlib.h>
/* �������������� ���������� �������, ����� �������� ���������, ������� �������
��������� ������������������ ��������:
�
BC
DEF
G�IJ
KLMNO
PQRSTU */

int main()
{
    int n, m;
    char c = 'A';
    for(n = 0; n < 6; n++)
        {
        for (m = 0; m <= n; m++, c++)
        printf("%c", c);

    printf("\n");
        }
    return 0;
}
