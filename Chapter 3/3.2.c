#include <stdio.h>
#include <stdlib.h>
 /* Нанишите программу, которая приглашает ввести некоторое значение в коде
ASCII, например, 66, а затем выводит символ, которому соответствует введенный
код. */

int main()
{
    int code;
    printf("Enter the ASCII code: \n");
    scanf("%d", &code);
    printf("The symbol of code is %c\n", code);


    return 0;
}
