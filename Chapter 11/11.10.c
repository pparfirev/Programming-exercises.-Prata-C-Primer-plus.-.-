/* �������� �������, ������� ��������� ������ � �������� ��������� � �������
�� ��� ��� �������. ������������� ��� ������� � ���������, ������� ����������
���� ��� ������ ����� �� ��� ���, ���� �� ����� ������� ������ ������.
��������� ������ ��������� ��� ������� � ������ ������� ������ � ����������
���������. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
void *space_del(char *str1);
char *s_gets(char *st, int n);
int main()
{
    char text1[SIZE];
    puts("Enter the text for string:");
    while(s_gets(text1, SIZE) && text1[0] != '\0')
    {
        puts("Before:");
        puts(text1);
        space_del(text1);
            puts("After:");
            puts(text1);
        puts("Enter the new text for string:");
    }
    puts("Program Closed.");
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin); // ���� ������ � ����������
    if(ret_val) // ���� ������ �������
    {
        while(st[i] != '\n' && st[i] != '\0') // ��������� �� ����� ������ ��� ������� ����� ������
            i++; // ��������� ��������
        if(st[i] == '\n') // ���� ������ ������ ����� ������
            st[i] = '\0'; // �� �������� ������ ��������� ������
        else // ��������� ������� words[i] == '\0'
            while(getchar() != '\n')
            continue;
    }
    return ret_val;
}
void *space_del(char *str1)
{
    int L = strlen(str1) - 1;
    int x = 0;
    char str1_new[SIZE]; // temporary massive
    for(int i = 0; i <= L; i++)
    {
        if(str1[i] != ' ') // If element !space
        {
            str1_new[x] = str1[i]; // assigning an element to a temporary array
            x++;
        }
    }
    for(int i = 0; i <= L; i++)
        str1[i] = str1_new[i]; // changing original massive
    return 0;
}
