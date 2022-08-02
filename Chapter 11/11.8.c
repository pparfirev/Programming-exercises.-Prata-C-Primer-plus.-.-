/* �������� ������� string_in(), ������� ��������� � �������� ����������
��� ��������� �� ������. ���� ������ ������ ���������� ������ ������, �������
������ ���������� �����, � �������� ���������� ������ ������ � ������ ������.
��������, ����� string_in ( "������", "��") ��������� ����� ������� � �
������ ������. � ��������� ������ ������� ������ ���������� ������� ���������.
������������� ������� � ����������� ���������, ������� ����������
���� ��� �������� ������� �������� ��������� �������. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
char *string_in(char *str1, char *str2);
char *s_gets(char *st, int n);
int main()
{
    char text1[SIZE], text2[SIZE];
    char answer;
    puts("Enter the text for first and second string:");
    while(s_gets(text1, SIZE) && s_gets(text2, SIZE) && text1[0] != '\0')
    {
        answer = string_in(text1, text2);
        if(answer)
            puts("The first string contains second string.");
        else
            puts("The first string doesn't contains second string.");
        puts("Enter the new text for first and second string:");
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
char *string_in(char *str1, char *str2)
{  int L = strlen(str2), i;
   while (*str1)
    {
     for(i = 0; i < L; i++)
       if (str1[i] != str2[i])
       break;
     if (i == L)
     return str1;
     str1++;
   }
   return NULL;
}

