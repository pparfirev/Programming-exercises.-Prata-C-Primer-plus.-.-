#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* �������� ���������, ������� ������ ���� ��� ����� ��������, ���� �� ��������
EOF. ��������� ������ �������� ������� ���������� ���� � ������. �� ��������
���������� ������� � ������ �������. �� ����� ����, ����� �� ������
����������� � ����� ����������, �� � ������ ���������� �� ���� ����� ��
������������. (��� ����� ������ ���������� ����� ��������������� ��������
ispunct () �� ��������� ctype.h. */
int main()
{
    int ch; // ��������� ������
    int count_words = 0; // ���������� ����
    int count_symb = 0; // ���������� ��������
    int count_synt = 0; // ���������� ������ ����������
    int mid_symb = 0; // ������� ���������� �������� � �����
    printf("Enter the text for symbols counting: ");
    while((ch = getchar()) != EOF)
    {
        if(ispunct(ch))
            count_synt++; // ������� �������� ����������
        else if(!(isspace(ch)) && !(ispunct(ch))) // ���� �� ���������� ������ � �� ������ ����������
            count_symb++; // �� ���� ������� ��������
        else if(isspace(ch)) // ���� ������ ����������
         count_words++; // �� ������� ����
    }
    mid_symb = count_symb / count_words; // ������� ���������� �������� ������������� ��� ����� ���������� �������� �������� �� ���������� ����
    printf("Total syntax symbols: %d; Total words: %d; Average number of letters in words: %d\n", count_synt, count_words, mid_symb);
    return 0;
}
