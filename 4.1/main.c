#include <stdio.h>
#include <stdlib.h>
/* 4.1 Ќапишите программу, котора€ запрашивает им€ и фамилию, а затем выводит их
в формате фамили€, им€. */

int main()
{
    char name[30], surname[50];
    printf("Enter you Name\n");
    scanf("%s", name);
    printf("Enter you Surname\n");
    scanf("%s", surname);
    printf("%s, %s", surname, name);
    return 0;
}
