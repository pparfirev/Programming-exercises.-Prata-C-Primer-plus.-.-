/* ������ ������� ������ ���������� � ����� �� ���� ������ � C�� � � ������
�� 100 ���������� � ������. ���� ��������� ����� ���������, ������� ����������
������������ ������� ����� (����������� ��� ������������), � �����
��������� ���� ������ � ��������� ������ �������:
// ��12-2�.�
// ������������� ������ � ��12-2�.�
#include <stdio.h>
#include "pel2-2a.h"
int main(void)
{
int mode;
printf ("������� � ��� ������������ ��^���� ��� 1 ��� ������������� ��^����: ");
scanf("%d", &mode);
while (mode >= 0)
{
set_mode(mode);
get_info();
show_info();
printf ("������� � ��� ������������ ������ ��� 1 ��� ������������� ��^���");
printf(" (-1 ��� ����������): ");
scanf("%d", &mode);
������ ��������, ���������� � ���������� ������� 527
printf("��������� ���������.\n");
return �;
}
���� ������� ������ ������:
������� 0 ��� ������������ ������ ��� 1 ��� ������������� ������: 0
������� ���������� ���������� � ����������: 600
������� ����� ���������������� ������� � ������: 78.8
������ ������� ���������� 13.13 ������ �� 100 ��.
������� 0 ��� ������������ ������ ��� 1 ��� ������������� ������ (-1 ��� ����������): 1
������� ���������� ���������� � ������: 434
������� ����� ���������������� ������� � ��������: 12.7
������ ������� ���������� 34.2 ���� �� ������.
������� � ��� ������������ ������ ��� 1 ��� ������������� ������ (-1 ��� ����������) : 3
������ ������������ �����. ������������ ����� 1 (������������).
������� ���������� ���������� � �����: 388
������� ����� ���������������� ������� � ��������: 15.3
������ ������� ���������� 25.4 ���� �� ������.
������� � ��� ������������ ������ ��� 1 ��� ������������� ������ (-1 ��� ����������): -1
��������� ���������.
���� ������������ ������ ������������ ����� , ��������� �������� �� ���� � ����������
�����, ������� ��� ������ � ��������� ���. ���������� ������������
���� ��12-2�. h � ���� ��������� ���� ��12-2�. �, ����� ����������
����������������� ���������. � ����� ��������� ���� ������ ������������
��� ���������� � �������� ��������� � �������� ����� � ���������� �����������.
���� ���������� ������������ �����, ������ - ���������� � ������
- ������ ������. ������� get_info () ����������� ���� ������ ��������
���������� ������ � ��������� ������ � ���������� � �������� ��������� �
�������� �����. ������� show_ info () ��������� � ���������� ������ �������
�� ������ ���������� ������. ������ �������, ��� ������������ ������ ������
�������� ��������.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pe12-2a.h"

int main(void)
{
    int mode;
    printf("Enter 0 for metric system or 1 for imperial system: ");
    scanf("%d", &mode);
    while(mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric system or 1 for imperial system (-1 for exit): ");
        scanf("%d", &mode);
    }
    return 0;
}
