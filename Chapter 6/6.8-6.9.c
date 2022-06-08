#include <stdio.h>
#include <stdlib.h>
/* Напишите программу, которая запрашивает два числа с плавающей запятой и
выводит значение их разности, деленной на их произведение. Программа должна
обрабатывать пары вводимых чисел до тех пор, пока пользователь не введет
нечисловое значение. */

/* Модифицируйте упражнение 8 так, чтобы программа использовала функцию для
возврага результатов вычислений. */

float result(float n, float p);
int main()
{
    float n1, n2, res;
    int stat1, stat2;
   // float result;
    stat1 = stat2 = 1;
    printf("Enter first float number: ");
    stat1 = scanf("%f", &n1);
    printf("Enter second float number: ");
    stat2 = scanf("%f", &n2);
    while(stat1 > 0 && stat2 > 0)
    {
        //res = (n1 - n2) / (n1 * n2);
        res = result(n1, n2);
        printf("Result is: %0.3f\n", res);
        printf("Enter new first float number: ");
        stat1 = scanf("%f", &n1);
        printf("Enter new second float number: ");
        stat2 = scanf("%f", &n2);
    }
    printf("Program is ended");
    return 0;
}

    float result(float n, float p)
{
 float resx = (n - p) / (n * p);
 return resx;
}
