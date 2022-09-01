/* �������� ���������, ������� ����� ���� ������� ����������� �������� 12.13,
������� ����������� ����� ������������� ������ �� ���������, ���������� �
�������� 12.13. �� ���� ��������� ������ ������ ����� ���������� ����:
    ������� ���������� �������� ��� q ��� ����������: 18
    ������� ������ � ������� ������? 6 3
    ����� 18 �������� 3 ������ � 6 �������.
    12 10 6 9 8 14 8 15 9 14 12 17 11 7 10
    13 8 14
������� ���������� �������� ��� q ��� ����������: q */

/* ������������� ������ � 12.7.1.c */
#include <stdio.h>
#include <stdlib.h> // for func srand()
#include <time.h> // for func time()
#include "12.7.1.h" // for func roll_n_dice() and var roll_count
int throws, dice;
int main(void)
{
    int roll;
    int sides, status;
    srand((unsigned int) time(0)); // randomize first var
    printf("Enter number of throws or press q for exit: ");
    while(scanf("%d", &throws) == 1 && throws > 0)
    {
        printf("How much sides and dices? ");
        if((status = scanf("%d%d", &sides, &dice)) != 2)
        {
        if(status == EOF)
            break; // exit the loop
            else
            {
                printf("You must entered int number.\nLets try again.\n");
            while(getchar() != '\n')
                continue; // cancelled wrong enter
            printf("Enter number of throws or press q for exit.\n");
            continue; // New loop iteration
            }
        }
        printf("We have %d throws with %d dices with %d sides.\n", throws, dice, sides);
    roll = roll_n_dice(throws, sides);
   // printf("You rolls the dice for %d times, using %d bones with %d edges.\n", roll, dice, sides);
    printf("\nEnter number of throws or press q for exit: ");
    }
    printf("Func rollem() was using for %d times.\n", roll_count - 1); // using extern var
    printf("Wish you luck.\n");
    return 0;
}
