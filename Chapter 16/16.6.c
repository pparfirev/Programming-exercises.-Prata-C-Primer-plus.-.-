/* Модифицируйте код в листинге 16.15 так, чтобы программа использовала массив
элементов struct names (как определено после листинга) вместо массива
элементов double. Задействуйте меньше элементов и явно инициализируйте
массив подходящим набором имен. */ // Опечатка в описании задания, необходима программа из листинга 16.17

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 5
typedef struct names
{
    char first[40];
    char last[40];
} name_list;
void showarray(const name_list ar[], int n);
int comp(const void *p1, const void *p2);
struct names staff[NUM] =
    {
        {"Name", "Surname"},
        {"Ivan", "Ivanov"},
        {"Jackie", "Jackson"},
        {"Billy", "Clinton"},
        {"Chris", "Brown"},
    };
int main()
{
    puts("List of Names and Surnames: ");
    showarray(staff, NUM);
    qsort(staff, NUM, sizeof(struct names), comp); // Calling qsort
    puts("\nSorted List: ");
    showarray(staff, NUM);
    return 0;
}
void showarray(const name_list ar[], int n)
{
    int index;
    for(index = 0; index < n; index++)
    {
        printf("%s %s\n", ar[index].last, ar[index].first);
        if(index % 6 == 5)
            putchar('\n');
    }
    if(index % 6 != 0)
        putchar('\n');
}
// Sort ascending
int comp(const void *p1, const void *p2)
{
    // Getting the right type of the pointer
    const struct names *ps1 = (const struct names *) p1;
    const struct names *ps2 = (const struct names *) p2;
    int res;
    res = strcmp(ps1->last, ps2->last); // Comparison
    if(res != 0)
        return res;
    else // Surnames are equal, so we need comparison the names
        return strcmp(ps1->first, ps2->first);
}

