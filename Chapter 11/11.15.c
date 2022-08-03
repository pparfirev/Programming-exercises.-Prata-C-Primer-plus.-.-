/*��� ���������� ���������� ������� atoi () ����������� ������� �������������
��������. ��� ������ ������ ���������� �������� �, ���� ������ ����� ��
�������� ��������� ��������. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 81
char *s_gets(char *st, int n);
int atoi_new(char *ch, int n);
int main()
{
    int ans;
    char text1[SIZE];
    puts("Enter the text for converting:");
    while(s_gets(text1, SIZE) && text1[0] != '\0')
    {
        ans = atoi_new(text1, strlen(text1));
        if(ans)
            printf("Number is %d\n", ans);
        else
            printf("Not an int string\n");

        puts("Enter the new text for converting:");
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
int atoi_new(char *st, int n)
{
    int res = 0;
    int exp = 1;
    for(int i = (n - 1); i >= 0; i--)
    {
        if(isalnum(st[i]) && !isalpha(st[i]))
        {
            res +=  (st[i] - '0') * exp;
            exp *= 10;
        }
        else
        return 0;
    }
    return res;
}
