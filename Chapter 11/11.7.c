/* ������� strncpy(sl, s2, n) �������� � �������� n �������� �� ������ s2 �
������ sl, ��� ������������� ������ s2 ��� �������� �� �������� ���������.
������� ������ ����� �� ��������� ������������ �������� �������, ����
����� ������ s2 ����� ��� ������ n. ������� ���������� ������ sl. ��������
���� ������ ���� ������� � �������� �� mystrncpy (). ������������� ������� �
����������� ���������, ������� ���������� ���� ��� �������� �������
�������� ��������� �������. */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
char *mystrcpy(char *str1, char *str2, int n);
char *s_gets(char *st, int n);
int main()
{
    char text1[SIZE], text2[SIZE];
    char answer;
    int count;
    puts("Enter the text for first and second string:");
    while(s_gets(text1, SIZE) && s_gets(text2, SIZE) && text1[0] != '\0')
    {
        puts("Enter the quality of symbols that need to copied from text2 to text1:");
        scanf("%d", &count);
        puts("Before:");
        puts(text1);
        puts(text2);
        printf("%d\n", count);
        answer = mystrcpy(text1, text2, count);
        puts("After:");
        puts(text1);
        puts(text2);
        printf("%d\n", count);
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
char *mystrcpy(char *str1, char *str2, int n)
{
    for(int i = 0; i < SIZE; i++)
    {
       if(i < n) // Copying only n symbols
        str1[i] = str2[i];
       else // another symbols of first string changing by NULL
        str1[i] = '\0';
    }
    return *str1;
}
