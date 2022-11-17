/* Авиакомпания Colossus Airlines (из упражнения 8) приобрела второй самолет
(с тем же количеством мест) и расширила обслуживание до четырех рейсов ежедневно
(рейсы с номерами 102, 311, 444 и 519). Модифицируйте программу для
обработки четырех рейсов. Она должна предлагать меню верхнего уровня, которое
позволяет выбирать интересующий рейс и выходить из программы. После
выбора рейса должно отобразиться меню, подобное показанному в упражнении 8.
Однако в него должен быть добавлен новый элемент — подтверждение брони
места. Кроме того, вариант выхода из программы потребуется заменить вариантом
возвращения в меню верхнего уровня. При каждом отображении должен
указываться номер рейса, обрабатываемого в текущий момент. Вдобавок при
отображении брони мест должно выводиться состояние подтверждения. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN         14
#define SEATS       12
#define FLIGHTS 4
#define EMPTY        0
#define TAKEN        1
#define CONTINUE     1
#define DONE         0

struct planestats {
    int seat_id;
    int status;
    int confirmation;
    char last[LEN];
    char first[LEN];
};
struct flights // structure of plane stats for every flight
{
    struct planestats plane_1[SEATS], *ps[SEATS];
};
int getmenu(void);
int getlet(const char *);
int openings(const struct planestats [], int);
void show_empties(const struct planestats [], int);
void list_assign(struct planestats *[], int);
void assign_seat(struct planestats [], int);
void delete_seat(struct planestats [], int);
void show_seats(const struct planestats [], int);
void sort(struct planestats *[], int);
void makelist(const struct planestats [], char *, int);
char * s_gets(char * st, int n);

int main(void)
{
    struct flights flight[FLIGHTS];
    int choice;
    int i;
    FILE *fp;
    size_t size = sizeof(struct planestats);
    for(int j = 0; j < FLIGHTS; j++)
        for (i = 0; i < SEATS; i++){
            flight[j].ps[i] = &flight[j].plane_1[i];
    }
    if ((fp = fopen("air.dat", "rb")) == NULL)
        for(int j = 0; j < FLIGHTS; j++)
        for (i = 0; i < SEATS; i++)
        {
            flight[j].plane_1[i].status = EMPTY;
            flight[j].plane_1[i].seat_id = i + 1;
            flight[j].plane_1[i].confirmation = 0;
        }
    else
    {
        for(i = 0; i < FLIGHTS; i++)
        fread(flight[i].plane_1, size, SEATS, fp);
        fclose(fp);
    }
    puts("Choose a flight from list or press 0 to exit: ");
    puts("102   411   444    519");
    int flight_choose;
    while(scanf("%d", &flight_choose) > 0 && flight_choose != 0)
    {
        //printf("%d\n", flight_choose);
        int index;
        while(getchar() != '\n')
            continue; // СleanUp enter string
            switch(flight_choose)
            {
                case 102: index = 0;
                break;
                case 411: index = 1;
                break;
                case 444: index = 2;
                break;
                case 519: index = 3;
                break;
                default :   puts("Wrong flight");
                            puts("Choose a flight from list or press 0 to exit: ");
                            puts("102   411   444    519");
                continue;
            }
    while ((choice = getmenu()) != 'f')
    {
        switch (choice)
        {
            case 'a': printf("There are %d empty seats.\n",
                      openings(flight[index].plane_1, SEATS));
                      break;
            case 'b': show_empties(flight[index].plane_1, SEATS);
                      break;
            case 'c': list_assign(flight[index].ps, SEATS);
                      break;
            case 'd': assign_seat(flight[index].plane_1, SEATS);
                      break;
            case 'e': delete_seat(flight[index].plane_1, SEATS);
                      break;
            default : puts("Switch trouble");
                      break;
        }
    }
        puts("Choose a flight from list or press 0 to exit: ");
        puts("102   411   444    519");
    }
    if ((fp = fopen("air.dat", "wb")) == NULL)
        puts("Can't save data to file.");
    else
    {
        for(int i = 0; i < FLIGHTS; i++)
            fwrite(flight[i].plane_1, size, SEATS, fp);
        fclose(fp);
    }
    puts("Bye from Colossus Airlines!");
    return 0;
}

#define CHOICES 6
int getmenu(void)
{
    const char *descript[CHOICES] = {
        "Show number of empty seats",
        "Show list of empty seats",
        "Show alphabetical list of seat assignments",
        "Assign a customer to a seat",
        "Delete a seat assignment",
        "Go to the topmenu"
    };
    const char labels[CHOICES + 1] = "abcdef";
    int i;

    puts("To choose a function, enter its letter label");
    for (i = 0; i < CHOICES; i++)
        printf("%c) %s\n", labels[i], descript[i]);
    return getlet(labels);
}

int getlet(const char * s)
{
    char c;

    c = getchar();
    while (strchr(s, c) == NULL)
    {
        printf("Enter a character in the list %s\n", s);
        while (getchar() != '\n')
            continue;
        c = getchar();
    }
    while (getchar() != '\n')
        continue;

    return c;
}

int openings(const struct planestats pl[], int n)
{
    int count = 0;
    int seat;

    for (seat = 0; seat < n; seat++)
        if (pl[seat].status == EMPTY)
            count++;
    return count;
}

void show_empties(const struct planestats pl[], int n)
{
    char seating[3 * SEATS];

    if (openings(pl, n) == 0)
        puts("All seats are assigned");
    else
    {
        puts("The following seats are available:");
        makelist(pl, seating, EMPTY);
        puts(seating);
    }
}

void makelist(const struct planestats pl[], char * str, int kind)
{
    int seat;
    char temp[LEN];

    str[0] = '\0';
    for (seat = 0; seat < SEATS; seat++)
        if (pl[seat].status == kind)
        {
            sprintf(temp, " %d", pl[seat].seat_id);
            strcat(str, temp);
        }
}

void list_assign(struct planestats *ps[], int n)
{
    int i = 0;
    if (openings(*ps, n) == SEATS)
        puts("All seats are empty.");
    else
    {
        sort(ps, n);
        for (i = 0; i < SEATS; i++)
            if (ps[i]->status == TAKEN)
                printf("Seat %d: %s, %s\n",
                    ps[i]->seat_id, ps[i]->last, ps[i]->first);
    }
}

void assign_seat(struct planestats pl[], int n)
{
    char list[3 * SEATS];
    int seat, loop;

    if (openings(pl, n) == 0)
        puts("All seats are assigned.");
    else
    {
        makelist(pl, list, EMPTY);
        puts("Which seat do you want? Choose from this list:");
        puts(list);
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                scanf("%*s");
                puts("Enter a number from this list:");
                puts(list);
            }
            if (seat < 1 || seat > SEATS ||
                pl[seat - 1].status == TAKEN)
            {
                puts("Enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
                loop = DONE;
        } while (loop == CONTINUE);
        while (getchar() != '\n')
            continue;
        puts("Enter first name:");
        s_gets(pl[seat - 1].first, LEN);
        puts("Enter last name:");
        s_gets(pl[seat - 1].last, LEN);
        printf("%s %s assigned to seat %d.\n",
        pl[seat - 1].first, pl[seat - 1].last, seat);
        puts("Enter a to accept assignment, c to cancel it.");
        if (getlet("ac") == 'a')
        {
            pl[seat - 1].status = TAKEN;
            puts("Passenger assigned to seat.");
        }
        else
            puts("Passenger not assigned.");
    }
}

void delete_seat(struct planestats pl[], int n)
{
    int seat, loop;
    char list[3 * SEATS];

    if (openings(pl, n) == SEATS)
        puts("All seats already are empty.");
    else
    {
        show_seats(pl, n);
        makelist(pl, list, TAKEN);
        puts("Enter the number of the seat to be cancelled:");
        do
        {
            while (scanf("%d", &seat) != 1)
            {
                scanf("%*s");
                puts("Enter a number from this list:");
                puts(list);
            }
            if (seat < 1 || seat > SEATS ||
                pl[seat - 1].status == EMPTY)
            {
                puts("Enter a number from this list:");
                puts(list);
                loop = CONTINUE;
            }
            else
                loop = DONE;
        } while (loop == CONTINUE);
        while (getchar() != '\n')
            continue;
        printf("%s %s to be cancelled for seat %d.\n",
            pl[seat - 1].first, pl[seat - 1].last, seat);
        puts("Enter d to delete assignment, a to abort.");
        if (getlet("da") == 'd')
        {
            pl[seat - 1].status = EMPTY;
            puts("Passenger dropped.");
        }
        else
            puts("Passenger retained.");
    }
}

void show_seats(const struct planestats pl[], int n)
{
    int i;

    puts("Seats currently taken:");
    for (i = 0; i < SEATS; i++)
        if (pl[i].status == TAKEN)
            printf("Seat %d: %s, %s\n", pl[i].seat_id,
                pl[i].last, pl[i].first);
}

void sort(struct planestats *array[], int limit)
{
    int top, search;
    struct planestats * temp;

    for (top = 0; top < limit - 1; top++)
        for (search = top + 1; search < limit; search++)
            if (strcmp(array[search]->last, array[top]->last) < 0)
            {
                temp = array[search];
                array[search] = array[top];
                array[top] = temp;
            }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}
