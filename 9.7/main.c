#include <stdio.h>
#include <stdlib.h>
/* �������� ���������, ������� ������ ������� �� ������������ ����� ������
�� ����� �����. ��� ������� ������� ��������� ������ ��������, ��������
�� �� ������. ���� ������ � �����, ��������� �������� ������ �������� ��
���������� ����� � ��������. ��������, ����� � � � ����� ����� ����� 3.
������������� � ��������� �������, ������� ��������� ������ � ��������
��������� � ���������� ��� ���������� ����� � ��������, ���� �� ��������
������, � -1 � ��������� ������. */
int conv(char lett);
int main()
{
    char symb;
    int num;
    printf("Enter the symbols for analysys: \n");
    while((symb = getchar()) != EOF)
    {
        num = conv(symb);
        printf("%c is '%d'\n", symb, num);
    }
    printf("Program Closed.\n");
    return 0;
}

int conv(char lett)
{
    int code;
    int count;
    if((lett >= 65 && lett <= 90)) // ANSI a = 97, A = 65
        code = lett - 64;
    else if(lett >= 97 && lett <= 122)
        code = lett - 96;
    else
        code = -1;
    return code;
}
