#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* �������� ���������, ������� ������ ����� � ���������� ������, � ����� �������
��� ����� � �������� �������. ���������: �������������� ��������
strlen() (����� 4) ��� ���������� ������� ���������� ������� �������. */

int main()
{
    int len;
    char word[20]; // ���������� �������
    printf("Enter the word: ");
    scanf("%s", &word);
    len = strlen(word); // ����� �������� �������
    while(len > 0)
    {
    printf("%c", word[len - 1]); // ��������� ������� ������� ������ ����� �� 1 (�.�. ������ ������� ��������� �� 0)
    len--;
    }
    return 0;
}