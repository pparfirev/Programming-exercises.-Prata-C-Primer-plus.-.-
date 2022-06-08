#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* ������������� ������� get_first () �� �������� 8.8 ���, ����� ��� ����������
������ ����������� ������������ ������. ������������� �� � �����-������
������� ���������. */
char get_choice();
char get_first();
int get_int();
void count(void);

int main()
{
    int choice;
    void count(void); // ���������� ������� ������ main
    while((choice = get_choice()) != 'q') // ���� ��������� ������ �� ����� q
    {
        switch(choice) // ������� � ����������� �� ���������� ������ ����
        {
            case 'a': printf("Buy cheap and sell expensive.\n");
            break;
            case 'r': putchar('\a'); // ����� �������
            break;
            case 'c': count(); // ����� ������� ��������
            break;
            default: printf("Error!\n"); // ���� ������ ����� ������ ������ �������� �� ������ (���� �� �� ���� �� �����)
            break;
        }
    }
    printf("Program closed.\n");
    return 0;
}

char get_choice(void) // ������� ������ ����
{
    int ch;
    printf("Enter the letter to choose the variant:\na. advice\tr. ring\nc. count\t q. exit\n");
    ch = get_first();
    while(ch != 'a' && ch != 'r' && ch != 'c' && ch != 'q') // ���� �� ���� ������ �� �������� �� ���������
    {
        printf("You must choose a, r, c or q\n"); // ��������� � ������������ �����
        ch = get_first(); // ��������� ����� ������� ������ ������
    }
    return ch; // ������� ���������� ������� � ����
}

char get_first(void) // ���� ������� ������� (��������� ������ ������������ ������)
{
    int ch;
    while(isspace(ch = getchar())) // ���� ��������� ������ ����������
    continue; // �� ���������� ��� �� ��� ��� ���� �� �������� "������������"
    while(getchar() != '\n') // ������� ������� ����� ������
        continue;
    return ch;
}

void count(void) // ������� ��������
{
    int n, i;
    printf("Enter the high limit for counting (int number).\n"); //����������� �� ���� ������� ��������
    n = get_int(); // ������� ������ ������ �����
    for(i = 1; i <= n; i++) // ������ �� ���������� �������
        printf("%d\n", i); // ����� ����� �� ����������� ��������
    while(getchar() != '\n') // ������� ������� ����� ������
        continue;
}
int get_int(void) // ���� ������ �����
{
    int input;
    char ch;
    while(scanf("%d", &input) != 1) // ���� ���� ��������
    {
        while(scanf((ch = getchar())) != '\n')
            putchar(ch); // ��������� ������ ����� ������
        printf("This is not int numb. Enter number like 4 8 15 16 or etc.\n"); // �������� � ������������ �����
    }
    return input; // ������� ���������� �����
}
