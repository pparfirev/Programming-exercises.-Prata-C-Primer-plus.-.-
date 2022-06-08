/* Компания АВС Mail Order Grocery продает артишоки по цене $2.05 за фунт, свеклу
по $1.15 за фунт и морковь по $1.09 за фунт. До добавления затрат на доставку
компания предоставляет скидку 5% на заказы на сумму $100 и выше. Затраты составляют
$6.50 за доставку и обработку заказа весом в 5 фунтов или менее, $14.00
за обработку и доставку заказа весом от 5 до 20 фунтов и $14.00 плюс $0.50 за
каждый фунт для доставки заказа с весом, превышающим 20 фунтов. Напишите
программу, которая использует оператор swi tch в цикле так, что в ответ на ввод
а пользователь получает возможность указать желаемый вес артишоков в фунтах;
в ответ на ввод Ь — вес свеклы в фунтах; в ответ на ввод с — вес моркови
в фунтах; а в ответ на ввод q — завершить процесс заказа. Программа должна
вести учет сумм нарастающим итогом. То есть если пользователь вводит 4 фунта
свеклы и позже вводит еще 5 фунтов свеклы, программа должна сообщать
о заказе 9 фунтов свеклы. Затем программа должна вычислить общие затраты,
скидку, если есть, расходы на доставку и полмую сумму заказа. Далее программа
должна отобразить всю информацию о покупке: стоимость фунта товара, количество
заказанных фунтов, стоимость каждого заказанного вида овощей, общую
стоимость заказа, скидку (если есть), затраты на доставку и итоговую сумму заказа
с угетом всех затрат.*/
#include <stdio.h>
#include <stdlib.h>
#define AR_PR 2.05 // Цена за фунт артишоков
#define BE_PR 1.15 // За фунт свеклы
#define CARR_PR 1.09 // За фунт моркови
#define DISC 0.95 // Скидка 5% при сумме заказа от 100$
#define DEL1 6.50 // Стоимость доставки до 5 фунтов
#define DEL2 14.00 // стоимость доставки от 5 до 20 фунтов

int main()
{
    char cat; // Категория выбора продуктов
    float art_w = 0, be_w = 0, car_w = 0; // Вес необходимых овощей;
    float art_w_t = 0, be_w_t = 0, car_w_t = 0; // Общее количество овощей
    float ar_pr_t = 0, be_pr_t = 0, car_pr_t = 0; // Общая цена выбранного веса овощей
    float pr_t = 0; // Общая цена всех овощей
    float veg_w = 0; // Общий вес всех овощей
    float pr_t_d = 0; // Цена с учетом доставки
    printf("Choose the production:\n");
    printf("a.Artichoke\nb.Beet\nc.Carrot\nq.Go to checkout\n"); // Выбор категории
    while(scanf("%c", &cat) == 1) // проверяется пока вводится символ (getchar зараза чет не работал нормально)
    {

        switch(cat)
        {
            case '\n': continue; // Необходимо пропускать символ новой строки в условии
            case 'a': printf("Enter the weight of artichoke you're need:\n"); // Если выбраны артишоки
                      scanf("%f", &art_w);
                      art_w_t += art_w; // прибавление веса при повторном выборе категории (задействовано для каждого овоща)
                      printf("Choose the category or press q to checkout:\n");
                      continue;
            case 'b': printf("Enter the weight of beet you're need:\n"); // Свека
                      scanf("%f", &be_w);
                      be_w_t += be_w;
                      printf("Choose the category or press q to checkout:\n");
                      continue;
            case 'c': printf("Enter the weight of carrot you're need:\n"); // Морковь
                      scanf("%f", &car_w);
                      car_w_t += car_w;
                      printf("Choose the category or press q to checkout:\n");
                      continue;
            case 'q': break; // при нажатии q переход к оформлению
            default:  printf("You must enter the symbol from a to c or q.\n"); // Если выбрано неправильноый вариант то обратно на страницу выбора
                      printf("Choose the category or press q to checkout:\n");
                      continue;

        }
    printf("You're totally choose: %0.2f pounds of artichoke, %0.2f pounds of beet and %0.2f pounds of carrot\n", art_w_t, be_w_t, car_w_t);
    ar_pr_t = art_w_t * AR_PR; // Стоимость артишоков
    be_pr_t = be_w_t * BE_PR; // Стоимость свеклы
    car_pr_t = car_w_t * CARR_PR; // Морковки
    pr_t = ar_pr_t + be_pr_t + car_pr_t; // Общая цена заказа до стоимости доставки
    veg_w = art_w_t + be_w_t + car_w_t; // Общий вес заказа
    printf("Your order %0.2f$ for artichoke, %0.2f$ for beet, %0.2f$ fot carrot.\nTotal price without delivery %0.2f%$, total weight %0.2f pounds.\n", ar_pr_t, be_pr_t, car_pr_t, pr_t, veg_w);
    if(pr_t >= 100) // Если сумма общего заказа на сумму 100$ или выше
    {
        pr_t = pr_t * DISC; // скидка 5%
        printf("Your discount is %0.2f$\n", pr_t * 0.05); //  Сообщение о скидке
    }
    if(veg_w <= 5) // Если вес 5 фунтов и меньше
        pr_t_d = pr_t + DEL1; // общая сумма
    else if(pr_t > 5 && pr_t <= 20) // если вес от 5 до 20
        pr_t_d = pr_t + DEL2;
    else // свыше 20
        pr_t_d = pr_t + DEL2 + (0.5 * (veg_w - 20)); // Общая сумма
    printf("Total price of your order is %0.2f$. (%0.2f$ for vegetables and %0.2f$ for delivery)\n", pr_t_d, pr_t, (pr_t_d - pr_t)); // Вывод всех данных
    printf("Choose the production:\n");
    printf("a.Artichoke\nb.Beet\nc.Carrot\nq.Go to checkout\n"); // Выбор категории
    }
    printf("Program Closed\n");
    return 0;
}
