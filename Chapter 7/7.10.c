/* В 1988 году шкала федеральных налоговых ставок Соединенных Штатов была самой
простой за все прошедшее время. Она содержала четыре категории, каждая
из которых включала две ставки. Ниже приведены самые общие данные (суммы
в долларах представляют собой доход, облагаемый налогом).
Категория                           Налог
Одинокий                            15% с первых $17 850 плюс 28% от суммы,
                                    превышающей указанную
Глава семейства                     15% с первых $23 900 плюс 28% от суммы,
                                    превышающей указанную
Состоит в браке, совместное         15% с первых $29 750 плюс 28% от суммы,
ведение хозяйства                   превышающей указанную
Состоит в браке, раздельное         15% с первых $14 875 плюс 28% от суммы,
ведение хозяйства                   превышающей указанную

Например, одинокий работник, получающий облагаемый налогом доход в
$20 ООО, платит налоги в сумме 0.15 х $17 8БО + 0.28 х ($20 $17 85О). Напишите
программу, которая позволяет пользователю указать категорию и облагаемый
налогом доход, после чего вычисляет сумму налога. Используйте цикл, чтобы
пользователь мог вводить разные варианты налогообложения */
#include <stdio.h>
#include <stdlib.h>
#define TAX 0.15 // Процентная ставка с первой суммы
#define TAX2 0.28 // Процентная ставка превышающая сумму
#define PAY1 17850 // Вверх суммы для одинокого
#define PAY2 23900 // Для главы семейства
#define PAY3 29750 // В браке совм. ведения хозяйства
#define PAY4 14875 // В браке, разд. ведения хозяйства

int main()
{
    int income; // Вводимый доход
    int cat; // Категория
    int pay; // Вверх по доходу в зависимости от категории
    float total_tax; // Общая сумма налогов
    printf("Enter your category:\n");
    printf("1.Lonely\n2.Head of the family\n3.Married, joint housekeeping\n4.Married, separate housekeeping\n5.Close the program\n");
    while(scanf("%d", &cat) == 1 && cat != 5) // В зависимсоти от выбранного числа выбирается определенная тарифная ставка, за исключением числа 5
    {
        switch(cat)
        {
            case 1: pay = PAY1;
                    break;
            case 2: pay = PAY2;
                    break;
            case 3: pay = PAY3;
                    break;
            case 4: pay = PAY4;
                    break;
            default: printf("You must enter the number from 1 to 5.\n"); // Если выбрано не 1 - 5 число то опять выбор
                    continue;
        }
        printf("Enter your income in dollars (non int quality for exit): \n");
        while(scanf("%d", &income) == 1)
        {
            if(income <= pay) // Если доход меньше или равен определенного потолка
                total_tax = income * TAX;
            else // Если выше
                total_tax = TAX * pay + TAX2 * (income - pay);
            printf("For your category and income your totally tax is %0.2f$.\n", total_tax); // Вывод облагаемого налога
            break;
        }
    printf("Enter your category:\n");
    printf("1.Lonely\n2.Head of the family\n3.Married, joint housekeeping\n4.Married, separate housekeeping\n5.Close the program\n");
    }
    printf("Program Closed\n");
    return 0;
}
