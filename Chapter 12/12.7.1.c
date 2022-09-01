#include <stdio.h>
#include <stdlib.h> // for func rand()
#include "12.7.1.h"
int roll_count = 1; // External binding
extern int throws, dice;
int roll_sum = 0;
static int rollem(int sides) // closed for that file
{
    int roll;
    roll = (rand() % sides + 1);
    roll_sum += roll;
    if(!(roll_count % dice))
    {
    printf("%d ", roll_sum);
    roll_sum = 0;
    }
    if(!(roll_count % (15 * dice)))
       printf("\n");
    roll_count++; // count func using
    return roll;
}
int roll_n_dice(int throws, int sides)
{
    int d;
    //int tot = dice * throws;
    int total = 0;
    if(sides < 2)
    {
        printf("You need at lease 2 edges.\n");
        return -2;
    }
    if(throws < 1)
    {
        printf("You need at least, 1 throw.\n");
        return -1;
    }
    for(d = 0; d < (dice * throws); d++)
        total += rollem(sides);
    return total;
}
