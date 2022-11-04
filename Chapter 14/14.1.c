/* Переделайте задание из вопроса 5 таким образом, чтобы артуменг был представлен
названием месяца, а не его номером. (Не забывайте о функции strcmp ().)
Протестируйте готовую функцию в простой программе. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct month
{
    char name[20];
    char abv[3];
    int days;
    int numb;
};
struct month months [12] =
{
    {"January", "JAN", 31, 1},
    {"February", "FEB", 28, 2},
    {"March", "MAR", 31, 3},
    {"April", "APR", 30, 4},
    {"May", "MAY", 31, 5},
    {"June", "JUN", 30, 6},
    {"July", "JUL", 31, 7},
    {"August", "AUG", 31, 8},
    {"September", "SEP", 30, 9},
    {"October", "OCT", 31, 10},
    {"November", "NOV", 30, 11},
    {"December", "DEC", 31, 12},
};
int days_m(char *mon);
int main()
{
    char ent_month[20];
    puts("Enter the name of month to get number of days since start of the year: ");
    scanf("%s", &ent_month);
    int days = days_m(ent_month);
    printf("Total days: %d.\n", days);
    return 0;
}
int days_m(char *mon)
{
    int days = 0;
    int equal = 0; // pointer for month is finding
    for(int n = 0; n < 13; n++)
    {
        days += months[n].days;
       if(!(strcmp(mon, months[n].name)))
       {
           equal = 1;
            break;
       }
    }
    if(!equal) // if month not finding enter the error message
    {
        puts("Wrong month.");
        days = 0;
    }
    return days;
}
