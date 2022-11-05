/* 4. Напишите программу, которая создает шаблон структуры с двумя членами в соответствии
со следующими критериями:
а. Первым членом является номер карточки социального страхования. Второй
член — это структура, состоящая из трех членов. Ее первый член содержит
имя, второй член — отчество и третий член — фамилию. Создайте и инициализируйте
массив из пяти таких структур. Программа должна выводить данные
в следующем формате:
Dribble, Flossie М. — 302039823
Выводиться должна только начальная буква отчества, за которой следует точка.
Разумеется, если этот член пуст, не должен выводиться ни инициал, ни точка.
Напишите функцию, которая выполняет такой вывод, передайте рассматриваемую
структуру этой функции. */
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
void OutData(struct info data[], int count); // Display data
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
        OutData(archv, count);
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
void OutData(struct info data[], int count)
{
    puts("Here's the list: ");
    for(int index = 0; index < count; index++)
    {
        if(strlen(data[index].name.mid_name)) // if string of middle name is not empty
            printf("\t%s, %s %c. -- %d\n", data[index].name.surname, data[index].name.name,
                   data[index].name.mid_name[0], data[index].ins_id);
        else
            printf("\t%s, %s -- %d\n", data[index].name.surname, data[index].name.name,
                   data[index].ins_id);
    }
};
