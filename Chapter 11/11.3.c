/* ������������ � ������������� �������, ������� ������ ������ ����� �� ������
����� � ������ � ����������� ��^������� ����� ������. ������� ������ ����������
������� ���������� �������. ���������� ����� ��� ������������������
��������, �� ���������� �������� �������, ��������� ��� ����� ������.
����������� ������� getchar(), � �� scanf(). */
#include <stdio.h>
#include <stdlib.h>
#define LEN 40
char *enter_n(char *str, int n);
int main()
{
    char mas[LEN];
    char *line;
    printf("Enter the text for saving in massive:\n");
    line = enter_n(mas, LEN);
    puts(line);
    return 0;
}
char *enter_n(char *str, int n)
{
    int i = 0, ch = 0;
    for(i = 0; i < n; i++)
    {
        ch = getchar();
        if(ch != EOF)
            str[i] = ch;
        else
            break;
        if(isspace(ch))
           break;
    }
   return str;

}
