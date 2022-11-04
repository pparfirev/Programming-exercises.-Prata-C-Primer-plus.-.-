/* Напишите программу, которая предлагает пользователю ввести день, месяц и год.
Месяц может быть представлен порядковым номером, названием или аббревиатурой.
Затем программа должна возвратить общее количество дней, истекших с
начала года по указанный день включительно. (Учитывайте високосные годы.) */
#include <stdio.h>
#include <stdlib.h>
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
int days_left(char *mon, int day);
int main()
{
    int day = 0;
    char ent_month[20];
    int ent_year;
    int days_tot;
    puts("Enter the day: ");
    while(scanf("%d", &day) == 1)
    {
    if(day > 0 && day < 32)
    {
        puts("Enter the month: ");
        scanf("%s", &ent_month);
        puts("Enter the year: ");
        scanf("%d", &ent_year);
        if(ent_year > 0)
        {

        if(!(ent_year % 4)) // If leap year
            months[1].days = 29;
        days_tot = days_left(ent_month, day);
        printf("Total days left since start of year %d is %d\n", ent_year, days_tot);
        months[1].days = 28; // return the standard value of days in february
        }
        else
        {
            puts("You must enter the integer year, enter right date");
            puts("Enter the date: ");
            continue;
        }
    }
    else
    {
        puts("You must enter the day between 1 and 31. Enter the day.");
        continue;
    }
    puts("Enter the day (or enter q to exit): ");
    }
    puts("Program Closed");
    return 0;
}
int days_left(char *mon, int day)
{
    int days = day;
    int equal = 0; // pointer for month is finding
    for(int n = 0; n < 13; n++)
    {
        if(!(strcmp(mon, months[n].name)))
       {
           if(day <= months[n].days)
            equal = 1;
           else
           {
                puts("You entered the wrong day of month!");
                days = -1;
           }
            break;
       }
        days += months[n].days;

    }
    if(!equal) // if month not finding enter the error message
    {
        puts("Error");
        days = -1;
    }
    return days;
}

