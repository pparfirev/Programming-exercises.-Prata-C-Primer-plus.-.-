#include <stdio.h>
#include <stdlib.h>
/* ��������� ���������� 4, �� � ����������� ��������� switch */
int main()
{
    char ch;
    int change = 0; // ���������� �����
       while((ch = getchar()) != '#') // ���� ������������ ���� �� ����� ������ #
    {
        switch(ch) // �������� �������
        {
            case '.': ch = '!'; // �� ������ ������ �� !
                      change++;
                      putchar(ch);
                      break;
            case '!': change++; // ���� ch !
                      putchar(ch); // �� ������ ������� ���
                      putchar(ch);
                      break;
            default: putchar(ch); // �� ������ ������� ���
    }
    }
    printf("\nTotally have %d changes.\n", change);
    return 0;
}
