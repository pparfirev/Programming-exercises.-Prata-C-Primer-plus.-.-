#include <stdio.h>
#include <stdlib.h>
/* 8. В главе 6 была показана функция power() (листинг 6.20), которая возвращает
результат возведения числа double в положительную целую степень.
Усовершенствуйте эту функцию, чтобы она корректно возводила числа в отрицательные
степени. Кроме того, добавьте в функцию возможность оценки как 0
результата возведения 0 в любую степень кроме 0 и оценки как 1 результата
возведения любого числа в степень 0. (Функция должна сообщать, что результат
возведения 0 в степень 0 не определен и что она использует значение 1.)
Примените цикл. Протестируйте функцию в какой-нибудь программе. */
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
        pow *= n;
    }
    else if(p < 0) // Если степень отрицательная
        for(i = -1; i >= p; i--) // То производится обратный отсчет в цикле
        {
        m_pow *= n; // дополнительная переменная чтобы рассчитать отрицательную степень
        pow = 1 / m_pow;
        }
    else
        pow = 1;
    return pow; // Возвратить значение pow (функция возвращает результат в виде переменной pow)
}
