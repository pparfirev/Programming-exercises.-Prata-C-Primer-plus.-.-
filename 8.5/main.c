#include <stdio.h>
#include <stdlib.h>
/* ������������� ��������� ���������� ����� �� �������� 8.4, ����� �����������
����� ���������������� ��������� ����������. ��������, ��������� �����
���������� ������������ ����� 50 � ���������, ������ �� ��� �����������,
������ ��� ��� �� ��� � ���� ���������� �����. ����, ������, �������������
������ ����������� �����, ��������� ������� ������ ���������� ���������
����� 50 � 100, �.�. 75. ���� ������ ������������� ������ ����������� �����,
�� ��������� ������� ������ ������������� ��������� ����� 75 � 50 � �.�.
��������� ����� ��������� ��������� ������, ��������� ������ ������ ����������
�����, �� ������ ������, ���� ������������ �� ����� ����������. */
int main()
{
    int guess = 50;
    char response;
    int low_guess = 0; // ������� �������� �������
    int high_guess = 0; // ������� �������� �������
    printf("Choose the int number from 1 to 99. And I'll try to guess it.\nPress button 'y' if I right and 'n' if I wrong.\n");
    printf("Your number is %d? Or less or bigger ('l' for less and 'b' for bigger)\n", guess);
    while((response = getchar()) != 'y') // �������� �����, �������� � Y
    {
        if(response == 'b') // ���� ���������� ����� ������ �������������
        {
            if(high_guess == 0 && low_guess != 0) // ��� ������ ����� � ���� ���� ������� ��� ���� �� � ������ ��� (�� �������� ��������, �� ��-������� �������� ��� �� ������
            {
                low_guess = guess;
                guess += ((100 - guess) / 2);
                printf("Well, so I think is %d.\n", guess);
                continue;
            }
            if(high_guess == 0 && low_guess == 0) // ���� ������ � ������� �������� ������� ��� �������������
            {
                low_guess = guess; // �� ��������� ������������ ����� ����� ������ �������� �������
                guess += ((100 - guess) / 2); // ���������� �� �������� �� ������������� ������� �����
                printf("Well, so I think is %d.\n", guess);
            }
            else // ���� ������� ������� ��� ��������
            {
            low_guess = guess; // �������� ������ ������  ������
            guess = low_guess + (high_guess - low_guess) / 2; // ����������� ������� �������� ����� ������� � ������� ��������
            printf("Well, so I think is %d.\n", guess);
            }
        }
        if(response == 'l') // ���� ����� ������ �������
        {
            if(high_guess == 0 && low_guess == 0) // � ���������� � ������ ���
            {
                high_guess = guess; // ���������� ������ ������
                guess = guess / 2; // � ������ ������� �������
                printf("Well, so I think is %d.\n", guess);
            }
            else // ���� ������� ���������� �� � ������ ���
            {
            high_guess = guess;
            guess = low_guess + (high_guess - low_guess) / 2; // ����� �� ������ �������� ����� ����� ���������
            printf("Well, so I think is %d.\n", guess);
            }
        }
        else
            printf("Please enter only 'y' or 'l' or 'b'.\n");
        while(getchar() != '\n')
            continue; // ���������� �������� ������ ����� ������
    }
    printf("I know that I can do it!\n");
    return 0;
}
