#include <stdio.h>
#include <stdlib.h>
#define f_sm 30.48
#define IN_SM 2.54
#define foot_inch 12

/* Напишите программу, которая запрашивает у пользователя ввод значения высоты
в сантиметрах, после чего отображает высоту в сантиметрах, а также в фу-
и дюймах. Должны быть разрешены дробные части сантиметров и дюймов.
Программа должна позволить пользователю продолжать ввод значений высоты
до тех пор, пока не будет введено неположительное значение. Вывод этой программы
должен иметь следующий вид:
Введите высоту в сантиметрах: 182
182.О см = 5 футов, 11.7 дюймов
Введите высоту в сантиметрах (<=О для выхода из программы) : 168.7
168.0 см = 5 футов, 6.4 дюймов
Введите высоту в сантиметрах (<=О для выхода из программы) : 0
Работа завершена. */

int main()
{
    float en_sm, inch;
    int foot;
    printf("Enter length in sm (<=0 for leave the program)\n");
    scanf("%f", &en_sm);
    while(en_sm >= 0)
    {
        foot = en_sm / f_sm;
        inch = (fmod(en_sm, f_sm)) / IN_SM;
        printf("%.1f = %d foots, %.1f inches\n", en_sm, foot, inch);
        printf("Enter the new length in sm (<=0 for leave the program)\n");
        scanf("%f", &en_sm);
    }
    printf("Program is ended\n");
    return 0;
}
