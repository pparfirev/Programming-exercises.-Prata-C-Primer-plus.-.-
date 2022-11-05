/* б. Модифицируйте часть а) так, чтобы вместо адреса передавалась сама структура. */
// Тут косяк в переводе по моему так как в оригинале пишется "Modify part a. by passing the structure value instead of the address."
// то есть передавать нужно значения структур
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 25
#define MAXP 100
char *s_gets(char *st, int n);
struct fullname
{
    char name[LEN];
    char mid_name[LEN];
    char surname[LEN];
};
struct info
{
    int ins_id;
    struct fullname name;
};
void OutData(int data, char name[LEN], char mid[LEN], char sur[LEN]); // Display data
int main()
{
    struct info archv[MAXP];
    int count = 0;
    printf("Enter the name: \n");
    printf("Or enter the empty string to stop entering.\n");
    while(count < MAXP && s_gets(archv[count].name.name, LEN) != NULL && archv[count].name.name[0] != '\0')
    {
        puts("Now enter the middle name: ");
        s_gets(archv[count].name.mid_name, LEN);
        puts("Now enter the surname: ");
        s_gets(archv[count].name.surname, LEN);
        puts("And enter the number of Insurance ID: ");
        scanf("%d", &archv[count++].ins_id);
        while(getchar() != '\n')
            continue; // Clean input string
        if(count < MAXP)
            printf("Enter the next name: \n");
    }
    if(count > 0)
    {
        puts("Here's the list: ");
        for(int index = 0; index < count; index++)
            OutData(archv[index].ins_id, archv[index].name.name, archv[index].name.mid_name, archv[index].name.surname);
    }
    else
        puts("Data is empty");
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n'); // NewLine searching
        if(find) // If adress doesn't NULL
            *find = '\0'; // Place ZeroSymbol
        else
            while(getchar() != '\n')
            continue; // Drop the end of the line
    }
    return ret_val;
}
void OutData(int data, char name[LEN], char mid[LEN], char sur[LEN])
{
        if(strlen(mid)) // if string of middle name is not empty
            printf("\t%s, %s %c. -- %d\n", sur, name,
                   mid[0], data);
        else
            printf("\t%s, %s -- %d\n", sur, name,
                   data);
};
