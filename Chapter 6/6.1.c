#include <stdio.h>
#include <stdlib.h>
/* �������� ���������, ������� ������� ������ �� 26 ��������� � �������� �
���� 26 �������� ���� ����������� ��������. ����� ������������� ����� �����������
����� �������. */
int main()
{
    char mas[26], b;
    int i;

    for(i = 0, b = 'a'; i < 26; i++, b++)
    {
        mas[i] = b;
        printf("%c ", mas[i]);
    }
    return 0;
}
