#include <stdio.h>
#include <stdlib.h>
/* Напишите программу, которая запрашивает ввод числа типа double и выводит
значение куба этого числа. Для этого используйте собственную функцию,
которая возводит значение в куб и выводит полученный результат. Программа
main () должна передавать этой функции вводимое значение. */

void coub(float n)
{
   n = n * n * n;
   printf("Coub is %.2f\n", n);
}

int main()
{
    float num;
    printf("Enter the numer\n");
    scanf("%f", &num);
    coub(num);
    return 0;
}
