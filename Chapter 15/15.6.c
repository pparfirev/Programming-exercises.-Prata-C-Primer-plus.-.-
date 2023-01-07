/* ������������ ��������� ������� �����, ������� �������� ��������� ����������:
    � ������������� ������: ����� �� 0 �� 255
    � ������ ������: ����� �� 0 �� 127
    � ������������: ����� �� 0 �� 2, �������������� ����� ������������ �����,
      �� ������ � ������
    � ����������: �������� (0) ��� ������� (1)
    � ������: �������� (0) ��� ������� (1)
    � ������������: �������� (0) ��� ������� (1)

    ����������� ��� ��������� � ���������, ������� ���������� ��������� ������
� ���� ������������ ����������� ������ ��������� � ������� ������������
����. ���� ���������� ������ ���������� ���������:

    ID  ������ ������������     �     �     �
    1   12     �����            ����. ����. ����.
    �) �������� �����   �) �������� ������      �) �������� ������������
    �) ����������       �) ������               �) ������������
    �) ���������
    �
    ������� ������ ������ (0-127) : 36
    ID  ������ ������������     �     �     �
    1   36     �����            ����. ����. ����.
    �) �������� �����   �) �������� ������      �) �������� ������������
    �) ����������       �) ������               �) ������������
    �)
    �
    �������� ������������:
    �) �����             �) �� ������           �) ������
    �
    ID  ������  ������������    �     �     �
    1   36      ������          ����. ����. ����.
    �) �������� �����   �) �������� ������      �) �������� ������������
    �) ����������       �) ������               �) ������������
    �) ���������
    �
    ID  ������  ������������    �     �     �
    1   36      ������          ����. ���   ����.
    �) �������� �����   �) �������� ������      �) �������� ������������
    �) ����������       �) ������               �) ������������
    �) ���������
    �
    ��������� ���������.

    ����� ���������� �������������� �������� �������� �������������� � �������
������ � �������� �� ���������� ���������, ��������� ������ ���������
�������� & � ���������� �����.
    */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define LEFT      0
#define CENTER    1
#define RIGHT     2
#define ID_MASK   0xFF
#define SIZE_MASK 0x7F

struct Font
{
    unsigned int id        : 8;
    unsigned int size      : 7;
    unsigned int           : 1;
    unsigned int alignment : 2;
    bool bold              : 1;
    bool italic            : 1;
    bool underline         : 1;
    unsigned int           : 3;

};
int main()
{
    struct Font font = {1, 12, 0, false, false, false};
    char ch;
    printf("ID\tSize\tAligment\tB\tI\tU\n");
    printf("%d\t%d", font.id, font.size);
    switch(font.alignment)
    {
        case 0: printf("\tLeft"); break;
        case 1: printf("\tCenter"); break;
        case 2: printf("\tRight"); break;
    }
    if(font.bold)
        printf("\t\tON");
    else
        printf("\t\tOFF");
    if(font.italic)
        printf("\tON");
    else
        printf("\tOFF");
    if(font.underline)
        printf("\tON");
    else
        printf("\tOFF");
    printf("\na. Change Font\t b. Change Size\t c. Change Alignment\n");
    printf("d. SemiBold\t e. Italic\t f. Underlined\n");
    printf("q. Quit\n");
    ch = getchar();
    while(ch != 'q')
    {
        switch(ch)
        {
            case 'a': printf("Enter new font from 0 to 255: ");
                      int fontID;
                      scanf("%d", &fontID);
                      font.id = fontID & ID_MASK;
                      break;
            case 'b': printf("Change font size from 0 to 127: ");
                      int sizeID;
                      scanf("%d", &sizeID);
                      font.size = sizeID & SIZE_MASK;
                      break;
            case 'c': printf("Choose Alignment:\n");
                      printf("l. Left\t\t c. Center\t r. Right\n");
                      getchar();
                      char alignmentID;
                      scanf("%c", &alignmentID);
                      switch(alignmentID)
                      {
                          case 'l': font.alignment = 0; break;
                          case 'c': font.alignment = 1; break;
                          case 'r': font.alignment = 2; break;
                          default: puts("Wrong Litera"); break;
                      }
                      break;
                      getchar();
            case 'd': font.bold = !font.bold; break;
            case 'e': font.italic = !font.italic; break;
            case 'f': font.underline = !font.underline; break;
            default: puts("Wrong Litera.");
        }
        getchar();
        printf("ID\tSize\tAligment\tB\tI\tU\n");
    printf("%d\t%d", font.id, font.size);
    switch(font.alignment)
    {
        case 0: printf("\tLeft"); break;
        case 1: printf("\tCenter"); break;
        case 2: printf("\tRight"); break;
    }
    if(font.bold)
        printf("\t\tON");
    else
        printf("\t\tOFF");
    if(font.italic)
        printf("\tON");
    else
        printf("\tOFF");
    if(font.underline)
        printf("\tON");
    else
        printf("\tOFF");
    printf("\na. Change Font\t b. Change Size\t c. Change Alignment\n");
    printf("d. SemiBold\t e. Italic\t f. Underlined\n");
    printf("q. Quit\n");
    ch = getchar();
    }
    return 0;
}
