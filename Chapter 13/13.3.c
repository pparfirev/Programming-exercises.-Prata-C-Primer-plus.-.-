/* �������� ��������� ����������� ������, ������� ���������� ������������
������ ��� ���������� �����. ������������ � ���� ���������, � ��� ���������
�����. ��������� ������ ������������ ������� toupper() �� ctype.h
��� �������� ������ � ������� ������� �� ����� ��� ������ � �������� ����.
���������� ����������� ����-����� � ��������� �����. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 255
int main()
{
    FILE *fp;
    FILE *in;
    char Or_filename[SIZE];
    char Copy_filename[SIZE];
    char ch;
    printf("Enter the original filename: ");
    gets(Or_filename); // put filename from
    if((fp = fopen(Or_filename, "r")) == NULL)
    {
        printf("Can't open original file %s\n", Or_filename);
        exit(EXIT_FAILURE);
    }
    printf("Now enter the file for copy: ");
    gets(Copy_filename);
    if((in = fopen(Copy_filename, "w")) == NULL) // stdinn setups
    {
        fprintf(stderr, "Can't open copying file  \"%s\"\n", Copy_filename);
        exit(EXIT_FAILURE);
    }
     while ((ch = getc(fp)) != EOF) // get symbols from origin file, until EOF
    {
        ch = toupper(ch); // Transformise symbol to upper
        putc(ch, in); // Enter symbol to copy file
    }
    fclose(fp);
    fclose(in);
    return 0;
}
