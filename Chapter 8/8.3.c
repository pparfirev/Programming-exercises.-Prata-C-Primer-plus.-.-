#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* �������� ���������, ������� ������ ���� ��� ����� ��������, ���� �� ��������
EOF. ��������� ������ �������� ���������� ��������� ���� ���������� ��������
���� � ���������� �������� �������� �� ������� ������. ������ ������������,
��� �������� �������� ��� �������� ���� �������� �����������������, � �� ��
����� ����������� ��� ��������� ����. ���� ��� ������� ������������� ������
������������ ���������� ����������������� ������� �� ���������� ct���.h. */

int main()
{
    int ch; // ��������� ������
    int Up_count = 0; // ���������
    int Low_count = 0; // ��������
    int Etc_count = 0; // ���������
    printf("Enter the text for symbols counting: ");
    while((ch = getchar()) != EOF)
    {
        if(islower(ch)) // ���� ������ ������� ��������
            Low_count++; // ��������� ��� �������
        else if(isupper(ch)) // ���� ������� �������
            Up_count++;
        else
            Etc_count++; // ������� ��������� ��������
    }
    printf("Lower_symb: %d, Upper_symb: %d, Etc_symb: %d", Low_count, Up_count, Etc_count);
    return 0;
}