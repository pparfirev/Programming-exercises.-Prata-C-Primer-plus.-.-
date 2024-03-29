#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* ������������� ���������� �� ���������������� 8 �� ����� 7 ���, ����� ������
���� ���������� �������, � �� �������; ��� ����������� ����� �����������
����� q ������ ����� 5. */

/* �������� ������������� �) � ���������� 7 ���, ����� ��������� �������������
���� � ��������� ��������. ��� ������ �������� ������ �����������
�������� switch. ����� ������� ��������� ����� ������ ���� �������� �����������
����:
*********************************************************************
������� �����, ��������������� �������� �������� ������ ��� ��������:
1) $8.75/�      2) $9.33/�
3) $10.00/�     4) $11.20/�
5) �����
*********************************************************************
���� ������ ������� � 1 �� 4, ��������� ������ ����������� ���������� ������������
�����. ��������� ������ ����������� �� ��� ���, ���� �� ����� ������
������� 5. ��� ����� ����-�� ��������� �� ��������� 1-5 ��������� ������
��������� ������������ ���������� �������� ��� ����� � ����� ������� ����.
��� ��������� �������� � ��������� ������ ���������� ��������� #define. */
#include <stdio.h>
#include <stdlib.h>
#define TAX1 0.85 // ��������� ������ �� 300 ��������
#define TAX2 0.8 // ��������� ������ �� 300 �� 450 ��������
#define TAX3 0.75 // ������ ����� 450 ��������
#define PAY1 (300 * TAX1) // ������������ ������� �� ������ ��������� ������
#define PAY2 ((450 - 300) * TAX2) // �������� �� ������ 20%
#define PAY40 400 // ������������ ������� �� ������� ������ �� ������ �������
#define OVERH 40 // ����������� ������ �� ����� � ������
#define TR1 8.75 // ��� ��� ������ �������� ������ ��� ������
#define TR2 9.33
#define TR3 10.00
#define TR4 11.20
int main()
{
    int hours;
    int pay;
    int tax_rate = 0; // ����� �������� ������
    float pay_tax;
    float price1, price2;
    printf("Enter the letter for tariff rate or action:\n");
    printf("a. $%0.2f\t\tb. $%0.2f\nc. $%0.2f\t\td. $%0.2f\nq. Exit\n", TR1, TR2, TR3, TR4);
    while((tax_rate = getchar()) != 'q') // � ����������� �� ���������� ����� ���������� ������������ �������� ������, �� ����������� ����� 5
    {
        switch(tax_rate)
        {
            case 'a': price1 = TR1;
                    break;
            case 'b': price1 = TR2;
                    break;
            case 'c': price1 = TR3;
                    break;
            case 'd': price1 = TR4;
                    break;
            case ' ': continue; // ��� ������ �� �������� ���������� �������� (���������, �� ��������)
            case '\t': continue;
            case '\n': continue; // ������� ������� ����� ������ (��� �����)
            default: printf("You must enter the letter from 'a' to 'd' or press 'q' for quit.\n"); // ���� ������� �� 1 - 5 ����� �� ����� �����
                    continue;
        }
     //   while(tax_rate != '\n')
       //     continue;

        price2 = price1 * 1.5; // ����� ����� ������������ ������ �� ������������ ������
    printf("Enter the quality of working hours per week (non int quality for exit): \n");
    while(scanf("%d", &hours) == 1) // ����� ������������ ����� (����������� ������ ����� �����)
    {
        if(hours <= 40) // ���� ���������� ����� 40 �����
        {
            pay = (hours * price1); // �� ������ �� �������� ������
            if(pay <= 300) // �� 300 �������� ��������� ������ 15%
            pay_tax = pay * TAX1;
            else // ����� 300 20%
            pay_tax = PAY1 + ((pay - 300) * TAX2);
        }
       if(hours > 40) // ���� ���������� ����� 40 �����
       {
           pay = PAY40 + ((hours - OVERH) * price2); // �������� ������������� ��� ������������ ����� �� �� 40 ����� ���� ����������� ���������� ����� �� ����� ������
           if(pay <= 450) // �� 450 �������� ������ 20% (�� 300 �� 450)
                pay_tax = PAY1 + ((pay - 300) * TAX2);
           else // ��� ����� ����� 450 ������ 20%
               pay_tax = PAY1 + PAY2 + ((pay - 450) * TAX3);
       }
       printf("Your pay for %d hours working per week is %0.2f. (%d dirty, and %0.2f taxes)\n", hours, pay_tax, pay, (pay - pay_tax));
       break;
    }
    printf("Enter the letter for tariff rate or action:\n");
    printf("a. $%0.2f\t\tb. $%0.2f\nc. $%0.2f\t\td. $%0.2f\nq. Exit\n", TR1, TR2, TR3, TR4);
    }
    printf("Program Closed\n");
    return 0;
}
