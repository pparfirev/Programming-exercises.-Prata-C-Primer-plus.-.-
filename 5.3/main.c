#include <stdio.h>
#include <stdlib.h>
#define dw 7
/* Напишите программу, которая запрашивает у пользователя ввод количества
дней и затем преобразует это значение в количество недемь и дней. Например,
18 дней программа должна преобразовать в 2 недели и 4 дня. Отображайте результаты
в следующем формате:
18 дней составляют 2 недели и 4 дня.
Чтобы пользователь мог многократно вводить количество дней, используйте
цикл while. Цикл должен завершаться при вводе пользователем неположительного
значения, например, О или -20. */

int main()
{
    int days, weeks, en_days;
    printf("Enter number of days\n");
    scanf("%d", &en_days);
    while(en_days > 0)
    {
    weeks = en_days / dw;
    days = en_days % dw;
    printf("%d days is %d weeks and %d days\n", en_days, weeks, days);
    printf("Enter number of days\n");
    scanf("%d", &en_days);
    }
    printf("Calculation is over.\n");
    return 0;
}
