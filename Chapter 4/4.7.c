#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/* Напишите программу, которая присваивает переменной типа double значение
1.0/3.0 и переменной тина float значение 1.0/3.0. Отобразите каждый результат
три раза: в первом случае с четырьмя цифрами справа от десятичной точки,
во втором случае с двенадцатью цифрами и в третьем случае с шестнадцатью
цифрами. Включите также в программу заголовочный файл float.h и выведите
значения FLT_DIG и DBL_DIG. Согласуются ли выведенные значения со значением
1.0/0.3? */
int main()
{
    double n_d;
    float n_f;
    n_d = 1.0 / 3.0;
    n_f = 1.0 / 3.0;
    printf("Result 4: double - %.4f, float -  %.4f\n", n_d, n_f);
    printf("Result 12: double - %.12f, float -  %.12f\n", n_d, n_f);
    printf("Result 16: double - %.16f, float -  %.16f\n", n_d, n_f);
    printf("Double - %d Float - %d", DBL_DIG, FLT_DIG);
    return 0;
}
