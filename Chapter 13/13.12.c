/* �������� ��������� ����, ��������� �� 20 ����� �� 30 ����� �����. ����� ��������
������ ������� � �������� �� 0 �� 9 � ���������� ���� �� ����� ���������.
���� �������� �������� �������������� �����������, ��� ���� ��������
�� 0 �� 9 ������������� ������������ ������ �������. �������� ���������,
������� ������ ���������� ����� ����� � ������ ��������� int � �������� 20
�� 30. ��� ������ ������� � �������������� ������ ��������� �������������
� ����������� ��������� ������ ������������ �������� �� ����� ������� ���
������������� ������� ��������� char � �������� 20 �� 31. ��� ���� 0 �������������
������� �������, 1 - ������� ����� � �.�.; ������� �������� ��������������
��������, ���������� ������� �������. ��������, ������ # �����
�������������� ��� ������������� �������� 9. ��������� ������ (31-�) � ������
������ ������ ���� �������, ������� � ����� ������ �� 20 �����. ���������
������ ���������� �������������� ����������� (�.�. ������� ������) � �����
��������� ��������� � ��������� �����. ��������, �����������, ��� ���������
������ �������� ���: */
/* 0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
   0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
   0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
   0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
   0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
   0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
   0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
   5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
   8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
   9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
   8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
   5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
   0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
   0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
   0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
   0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
   0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
   0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
   0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
   0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 255
int main()
{
    int mas[20][30];
    char masout[20][31];
    FILE *fp;
    int ch;
    char filename[SIZE];
    printf("Enter the filename: ");
    gets(filename); // put filename from

    if((fp = fopen(filename, "r")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
        for(int x = 0; x < 20; x++)
            for(int y = 0; y < 30; y++)
            fscanf(fp, "%d", &mas[x][y]); // put numbers from file to a massive

       /* for(int x = 0; x < 20; x++) // code for checking create massive
        {
            putchar('\n');
            for(int y = 0; y < 30; y++)
            printf("%d ", mas[x][y]);
        } */

        for(int x = 0; x < 20; x++)
        {
            //putchar('\n');
            for(int y = 0; y < 30; y++) // put different char to a masout depending value of element of mas
            switch(mas[x][y])
        {
            case 0: //putchar(' ');
                    masout[x][y] = ' ';
            break;
            case 1: //putchar('.');
                    masout[x][y] = '.';
            break;
            case 2: //putchar('\'');
                    masout[x][y] = '\'';
            break;
            case 3: //putchar(':');
                    masout[x][y] = ':';
            break;
            case 4: //putchar('~');
                    masout[x][y] = '~';
            break;
            case 5: //putchar('*');
                    masout[x][y] = '*';
            break;
            case 6: //putchar('=');
                    masout[x][y] = '=';
            break;
            case 7: //putchar('+');
                    masout[x][y] = '+';
            break;
            case 8: //putchar('%');
                    masout[x][y] = '%';
            break;
            case 9: //putchar('#');
                    masout[x][y] = '#';
            break;
            default: //putchar(' ');
                    masout[x][31] = ' ';
            break;
        }
        }
        for(int x = 0; x < 20; x++) // put a zero symbol to every 31-st y value of masout
            masout[x][30] = '\0';
        for(int x = 0; x < 20; x++)  // Showing masout content
        {
            putchar('\n');
            for(int y = 0; y < 31; y++)
            printf("%c ", masout[x][y]);
        }

    fclose(fp);
    return 0;
}
