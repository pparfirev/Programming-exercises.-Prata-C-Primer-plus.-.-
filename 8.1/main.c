#include <stdio.h>
#include <stdlib.h>
/* �������� ���������, ������� ������������ ���������� �������� �� �������
������ �� ���������� ����� �����. */
int main()
{
    int count = 0; // ������� ����� ��������
    int ch; // ������
    printf("Enter the text for symbols counting: ");
    while((ch = getchar()) != EOF)
        count++;
    printf("Text has %d symbols\n", count - 1); // ������������� ������� ������� ����� ������
    return 0;
}
