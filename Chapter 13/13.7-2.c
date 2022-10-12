/* �������� ���������, ������� ��������� ��� �����. �������� ����� ������
����� ���� ����� ��������� ������, ���� ��������� ������������ ������ ��.
    �. �������� ���, ����� ��� ��������� �������� ������ 1 ������� �����, ������ 1
������� �����, ������ 2 ������� �����, ������ 2 ������� ����� � �.�., ���� ��
����� �������� ��������� ������ ����� �������� (�� ���������� �����) �����.
    �. ������������� ��������� ���, ����� ������ � ����� � ��� �� ������� ����������
� ����� �������� ������. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LEN 25

int main()
{
    FILE *first, *sec; // two pointers on FILE
    int ch;
    char First_filename[LEN];
    char Sec_filename[LEN];
    char name[LEN]; // place for output name file
    bool Firstfile, Secondfile;
    Firstfile = Secondfile = true;
    printf("Enter the first filename: ");
    gets(First_filename); // put filename from
    if((first = fopen(First_filename, "r")) == NULL) // stdinn setups
    {
        fprintf(stderr, "Can't open file \"%s\"\n", First_filename);
        exit(EXIT_FAILURE);
    }
    printf("Enter the second filename: ");
    gets(Sec_filename); // put filename from
    if((sec = fopen(Sec_filename, "r")) == NULL) // stdinn setups
    {
        fprintf(stderr, "Can't open file \"%s\"\n", Sec_filename);
        exit(EXIT_FAILURE);
    }

    while(Firstfile || Secondfile)
    {
    while((ch = getc(first)) != EOF)
    {
        if(ch == '\n')
                break;
            else
                putchar(ch);
    }
    if(ch == EOF)
            Firstfile = false;
    putchar(' ');
    while((ch = getc(sec)) != EOF)
    {
        if(ch == '\n')
                break;
            else
                putchar(ch);
    }
    if(ch == EOF)
            Secondfile = false;
        putchar('\n');
    }
    fclose(first);
    fclose(sec);
    return 0;
}
