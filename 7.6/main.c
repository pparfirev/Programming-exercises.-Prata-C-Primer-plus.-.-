#include <stdio.h>
#include <stdlib.h>
/* �������� ���������, ������� ������ ������� ������, ���� �� �������� ������
#, � �������� ���������� ��������� ������������������ ei.
�� �������!
��� ��������� ������ �����������" ���������� ������, � ����� ������� ������.
��������� �� �� ������� ������������������ ����� �Receive your eieio award#�. */
int main()
{
    char ch;
    int ch1 = 0;
    int count = 0; // ���� ������ �������� ������ ������� � ������
    printf("Enter the text for analisys, and enter '#' at the end.\n");
    while((ch = getchar()) != '#') // ���� ������������ ���� �� ����� ������ #
    {
        if(ch == 'e')
        {
            ch1 = 1;
            continue;
        }
        if(ch == 'i' && ch1)
            count++;
        ch1 = 0;
    }
    printf("Totally have %d subsequences.\n", count);
    return 0;
}
