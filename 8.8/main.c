#include <stdio.h>
#include <stdlib.h>
/* �������� ���������, ������� ������� �� ����� ����, ������������ ������� ��������,
���������, ��������� ��� �������. ����� ������ ��������� ������ ��������� ��� �����
� ����� ��������� ������������� ��������. ��������� ������ ���������
������ ��������, ������������ � ����. ��� ����� ������ ��������������
��� float � ��������� ������ ������������� ������������ ����������� ��������
������� �����, ���� �� ���� ���������� ������. � ������ ������� ��������� ������
���������� ������������ ������ ������ ��������, ���� �� ���� ��� ������� ��������
�������� 0. ���������� ����� ��������� ������ ����� �������� ����� ���: */

/* �������� �������� ��������:
�. ��������     �. ���������
�. ���������    �. �������
�. ����������
�
������� ������ �����: 22.4
������� ������ �����: ����
���� �� �������� ������.
������� �����, ����� ��� 2.5, -1.78�8 ��� 3: 1
22.4 + 1 = 23.4
�������� �������� ��������:
�. �������� �. ���������
�. ��������� �. �������
�. ����������
�
������� ������ �����: 18.4
������� ������ �����: 0
������� �����, �������� �� 0: 0.2
18.4 / 0.2 = 92
�������� �������� ��������:
�. �������� �. ���������
�. ��������� �. �������
�. ����������
s
��������� ���������. */
float get_num(void);
int main()
{

    float ans; // ��������� ��������
    int oper; // ��������� ��������
    float n1, n2; // ����� ��� ��������
    printf("Enter the desired operation:\na.Addition\t\tb.Subtraction\nc.Multiplication\td.Division\nq.Quit\n"); // ���� ��� �����
    while((oper = getchar()) != 'q') // ����������� ��� �������� �� ����������� ������
    {
        switch(oper)
        {
            case '\n': continue; // ������� �������
            case 'a': printf("Enter the first number: "); // ��������
                      n1 = get_num(); // ���� �����
                      printf("Enter the second number: ");
                      n2 = get_num();
                      ans = n1 + n2;
                      printf("%0.2f + %0.2f = %0.2f\n", n1, n2, ans); //�����
                      break;
            case 'b': printf("Enter the first number: "); // ����� � ����������
                      n1 = get_num();
                      printf("Enter the second number: ");
                      n2 = get_num();
                      ans = n1 - n2;
                      printf("%0.2f - %0.2f = %0.2f\n", n1, n2, ans);
                      break;
            case 'c': printf("Enter the first number: "); // ����������
                      n1 = get_num();
                      printf("Enter the second number: ");
                      n2 = get_num();
                      ans = n1 * n2;
                      printf("%0.2f * %0.2f = %0.2f\n", n1, n2, ans);
                      break;
            case 'd': printf("Enter the first number: "); // � ��������
                      n1 = get_num();
                      printf("Enter the second number: ");
                      n2 = get_num();
                      while(n2 == 0) // � ����� �������, ���� �������� ����� ����
                      {
                          printf("Enter the number not equal to 0: "); // �� ������ �� ���� ������ �����
                          n2 = get_num();
                      }
                      ans = n1 / n2;
                      printf("%0.2f * %0.2f = %0.2f\n", n1, n2, ans); // �����
                      break;
            default: printf("You must choose letters from 'a' to 'd' or 'q'\n"); //���� ������� ������������ ����� ����
                     break;
        }
        printf("Enter the desired operation:\na.Addition\t\tb.Subtraction\nc.Multiplication\td.Division\nq.Quit\n"); // ����������� �� ��������� ����� ��������
    }
    printf("Program closed.\n"); // �������� ���������
    return 0;
}


float get_num(void) // ������� ����� ����� (������ �����, ������ ��� �� ������� ������� ��� ���������)
{
    int ch; // ��� ������ ��������
    float input; // ������� ��������
    while(scanf("%f", &input) != 1) // ���� ������� ���������� ��������
    {
        while((ch = getchar()) != '\n') // ������� �������
            putchar(ch); // ����� ���������� �������� �����������
        printf(" is not a number.\nEnter a right number!: "); // ���������
    }
    return input; // ������� ���������� ��������� ��������
}

