/* Гармоническое среднее двух чисел получается путем вычисления среднего от инверсий
этих чисел с последующим инвертированием результата. Воспользуйтесь
директивой #define для определения функционального макроса, который выполняет
эту операцию. Напишите простую программу для тестирования этого макроса. */
#include <stdio.h>
#include <stdlib.h>
#define HARM(X, Y) printf("Harmonic mean of number %.2lf and %.2lf is %.3lf.\n", X, Y, (2 / ((1 / X) + (1 / Y))));
int main()
{
    double n1;
    double n2;
    printf("Print 2 number to calculate Harmonic mean or press q to quit: ");
    while(scanf("%lf %lf", &n1, &n2) == 2)
    {
        HARM(n1, n2);
        printf("Print 2 number to calculate Harmonic mean or press q to quit: ");
    }
    puts("Program Closed.");
    return 0;
}
