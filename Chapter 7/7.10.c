/* � 1988 ���� ����� ����������� ��������� ������ ����������� ������ ���� �����
������� �� ��� ��������� �����. ��� ��������� ������ ���������, ������
�� ������� �������� ��� ������. ���� ��������� ����� ����� ������ (�����
� �������� ������������ ����� �����, ���������� �������).
���������                           �����
��������                            15% � ������ $17 850 ���� 28% �� �����,
                                    ����������� ���������
����� ���������                     15% � ������ $23 900 ���� 28% �� �����,
                                    ����������� ���������
������� � �����, ����������         15% � ������ $29 750 ���� 28% �� �����,
������� ���������                   ����������� ���������
������� � �����, ����������         15% � ������ $14 875 ���� 28% �� �����,
������� ���������                   ����������� ���������

��������, �������� ��������, ���������� ���������� ������� ����� �
$20 ���, ������ ������ � ����� 0.15 � $17 8�� + 0.28 � ($20 $17 85�). ��������
���������, ������� ��������� ������������ ������� ��������� � ����������
������� �����, ����� ���� ��������� ����� ������. ����������� ����, �����
������������ ��� ������� ������ �������� ��������������� */
#include <stdio.h>
#include <stdlib.h>
#define TAX 0.15 // ���������� ������ � ������ �����
#define TAX2 0.28 // ���������� ������ ����������� �����
#define PAY1 17850 // ����� ����� ��� ���������
#define PAY2 23900 // ��� ����� ���������
#define PAY3 29750 // � ����� ����. ������� ���������
#define PAY4 14875 // � �����, ����. ������� ���������

int main()
{
    int income; // �������� �����
    int cat; // ���������
    int pay; // ����� �� ������ � ����������� �� ���������
    float total_tax; // ����� ����� �������
    printf("Enter your category:\n");
    printf("1.Lonely\n2.Head of the family\n3.Married, joint housekeeping\n4.Married, separate housekeeping\n5.Close the program\n");
    while(scanf("%d", &cat) == 1 && cat != 5) // � ����������� �� ���������� ����� ���������� ������������ �������� ������, �� ����������� ����� 5
    {
        switch(cat)
        {
            case 1: pay = PAY1;
                    break;
            case 2: pay = PAY2;
                    break;
            case 3: pay = PAY3;
                    break;
            case 4: pay = PAY4;
                    break;
            default: printf("You must enter the number from 1 to 5.\n"); // ���� ������� �� 1 - 5 ����� �� ����� �����
                    continue;
        }
        printf("Enter your income in dollars (non int quality for exit): \n");
        while(scanf("%d", &income) == 1)
        {
            if(income <= pay) // ���� ����� ������ ��� ����� ������������� �������
                total_tax = income * TAX;
            else // ���� ����
                total_tax = TAX * pay + TAX2 * (income - pay);
            printf("For your category and income your totally tax is %0.2f$.\n", total_tax); // ����� ����������� ������
            break;
        }
    printf("Enter your category:\n");
    printf("1.Lonely\n2.Head of the family\n3.Married, joint housekeeping\n4.Married, separate housekeeping\n5.Close the program\n");
    }
    printf("Program Closed\n");
    return 0;
}
