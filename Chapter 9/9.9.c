#include <stdio.h>
#include <stdlib.h>
/* 9. Еще раз выполните упражнение 8, но на этот раз используйте рекурсивную
функцию. */
double power(double n, int p);

int main()
{
    double x, xpow;
    int exp;
    printf("Enter the number and positive int exp.\nFor exit the program enter 'q'\n");
    while(scanf("%lf%d", &x, &exp) == 2) // Принимает два введенных числа (исходное и его степень) функция возвращает 2 когда оба числа введены верно
    {
        xpow = power(x, exp); // Вызов функции
        if(xpow == 1 && x == 0 && exp == 0)
            printf("this is incorrect answer, because 0 to the power of 0 is not determined.\n"); // Уточнение для того, что результаты расчета неверны при 0^0
        printf("%.3g to the power of %d is %0.5lf\n", x, exp, xpow);
        printf("Enter the next number and positive int exp.\nFor exit the program enter 'q'\n");
    }
    return 0;
}

double power(double n, int p) //Прототип ANSI
{
    double pow = 1, m_pow = 1;
    int i;
    if(n == 0 && p == 0) // Если число и его степень выбраны 0
        pow = 1;
    else if(p > 0)
    {
    for (i = 1; i <= p; i++)
        pow = n * power(n, p - 1); // рекурсивная функция
    }
    else if(p < 0) // Если степень отрицательная
        for(i = -1; i >= p; i--) // То производится обратный отсчет в цикле
        {
        m_pow = n * (n, p); // дополнительная переменная чтобы рассчитать отрицательную степень (с рекурсией)
        pow = 1 / m_pow;
        }
    else
        pow = 1;
    return pow; // Возвратить значение pow (функция возвращает результат в виде переменной pow)
}
