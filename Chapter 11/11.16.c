/* �������� ���������, ������� ������ ������� ������ �� ��� ���, ���� �� ����������
EOF, � ������� �� �� �����. ��������� ������ ������������ � �������������
��������� ��������� ��������� ������:
    -� ����� ������� ������ � ��� ����, ��� ����.
    -u �������������� ������� ������ � ������� �������.
    -1 �������������� ������� ������ � ������ �������.
����� ����, �c�� �������� ������� ������ �� ������, ��������� ������ �����
���� ���, ��� ���� �� ��� ����� �������� -�. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 81
#define STRING 20

int main(int argc, char *argv[])
{
    int ch;
    if(argv[1][0] == '-')
    {
    if(argv[1][1] == 'p')
    {
        while((ch = getchar()) != EOF)
            putchar(ch);
    }
    if(argv[1][1] == 'u')
    {
        while((ch = getchar()) != EOF)
            putchar(toupper(ch));
    }
    if(argv[1][1] == 'l')
    {
        while((ch = getchar()) != EOF)
            putchar(tolower(ch));
    }
    else
    {
        while((ch = getchar()) != EOF)
            putchar(ch);
    }
    }
    elseYe
        {
        while((ch = getchar()) != EOF)
            putchar(ch);
        }
}
