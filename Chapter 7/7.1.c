#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>
/* �������� ���������, ������� ������ ������� ������ �� ��� ���, ���� �� ����������
������ #, � ����� ���������� ���������� ����������� ��������, ����������
�������� ����� ������ � ���������� ���� ��������� ��������. */

int main()
{
    char ch;
    int spaces = 0;
    int lines = 0;
    int symb = 0;
    printf("Enter the text for analisys, and enter '#' at the end.\n");
    while((ch = getchar()) != '#') // ���� ������������ ���� �� ����� ������ #
    {
        if(ch != '\n') // ������ ����� ������ �� �����, ������� �� ������ � �������
        symb++;
        if(ch == ' ') // ���� ������ ����������, �� ������������� ������� ��������
            spaces++;
        if(ch == '\n') // ���� ����� ������, �� ������� �������� ����� ������
            lines++;
    }
    printf("In your text %d all symbols, %d lines and %d spaces.\n", symb, lines, spaces);
    return 0;
}
