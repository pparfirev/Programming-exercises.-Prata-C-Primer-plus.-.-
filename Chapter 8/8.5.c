#include <stdio.h>
#include <stdlib.h>
/* ћодифицируйте программу угадывани€ чисел из листинга 8.4, чтобы реализовать
более интеллектуальную стратегию угадывани€. Ќапример, программа может
изначально предположить число 50 и запросить, больше ли оно задуманного,
меньше его или же это и есть задуманное число. ≈сли, скажем, предположение
меньше задуманного числа, следующа€ догадка должна находитьс€ посредине
между 50 и 100, т.е. 75. ≈сли данное предположение больше задуманного числа,
то следующа€ догадка должна располагатьс€ посредине между 75 и 50 и т.д.
»спользу€ такую стратегию двоичного поиска, программа быстро найдет нравильный
ответ, во вс€ком случае, если пользователь не будет обманывать. */
int main()
{
    int guess = 50;
    char response;
    int low_guess = 0; // ћеньшее значение выборки
    int high_guess = 0; // Ѕольшее значение выборки
    printf("Choose the int number from 1 to 99. And I'll try to guess it.\nPress button 'y' if I right and 'n' if I wrong.\n");
    printf("Your number is %d? Or less or bigger ('l' for less and 'b' for bigger)\n", guess);
    while((response = getchar()) != 'y') // ѕолучить ответ, сравнить с Y
    {
        if(response == 'b') // ≈сли загаданное число больше предложенного
        {
            if(high_guess == 0 && low_guess != 0) // “ут короче заход в цикл если выборка уже идет не в первый раз (да выгл€дит костылем, но по-другому работать чет не хотела
            {
                low_guess = guess;
                guess += ((100 - guess) / 2);
                printf("Well, so I think is %d.\n", guess);
                continue;
            }
            if(high_guess == 0 && low_guess == 0) // ≈сли нижнее и верхнее значение выборки еще неопределенно
            {
                low_guess = guess; // то последнее предложенное число будет нижним пределом выборки
                guess += ((100 - guess) / 2); // увеличение на половину от максимального вз€того числа
                printf("Well, so I think is %d.\n", guess);
            }
            else // ≈сли пределы выборки уже известны
            {
            low_guess = guess; // задаетс€ нижний предел  поиска
            guess = low_guess + (high_guess - low_guess) / 2; // подбираетс€ среднее значение между большим и меньшим пределом
            printf("Well, so I think is %d.\n", guess);
            }
        }
        if(response == 'l') // ≈сли число меньше выборки
        {
            if(high_guess == 0 && low_guess == 0) // и выбираетс€ в первый раз
            {
                high_guess = guess; // назначетс€ высший предел
                guess = guess / 2; // » просто делитс€ пополам
                printf("Well, so I think is %d.\n", guess);
            }
            else // ≈сли выборка происходит не в первый раз
            {
            high_guess = guess;
            guess = low_guess + (high_guess - low_guess) / 2; // такой же расчет среднего между двум€ пределами
            printf("Well, so I think is %d.\n", guess);
            }
        }
        else
            printf("Please enter only 'y' or 'l' or 'b'.\n");
        while(getchar() != '\n')
            continue; // ѕропустить вводимый символ новой строки
    }
    printf("I know that I can do it!\n");
    return 0;
}
