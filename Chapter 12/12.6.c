/* Напишите программу, которая генерирует 1000 случайных чисел в диапазоне от
1 до 10. Не сохраняйте и не выводите эти числа, а выводите лишь то, сколько раз
генерировалось каждое число. Программа должа делать это для 10 разных начальных
значений. Появляются ли числа в одинаковых количествах? Можете использовать
функции из этой главы или функции rand () и srand () из ^ANSI С, которые
следуют тому же формату, что и рассмотренные здесь. Это один из способов исследования
недетерминированности конкретного генератора случайных чисел. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000 // quality of random numbers
static int one, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0, ten = 0;
int main(void)
{
    int count;
    int num;
    srand((unsigned int) time(0)); // Different start values using form func srand and time
    for(count = 0; count < SIZE; count++)
    {
        num = 1 + (rand() % 10);
       // printf("%d ", num);
        switch(num) // counting numbers from massive
        {
            case 1: one++;
                      break;
            case 2: two++;
                      break;
            case 3: three++;
                      break;
            case 4: four++;
                      break;
            case 5: five++;
                      break;
            case 6: six++;
                      break;
            case 7: seven++;
                      break;
            case 8: eight++;
                      break;
            case 9: nine++;
                      break;
            case 10: ten++;
                      break;
        }
    }
    printf("Totally: 1 - %d, 2 - %d, 3 - %d, 4 - %d, 5 - %d,\n6 - %d, 7 - %d, 8 - %d, 9 - %d, 10 - %d\n", one, two,
           three, four, five, six, seven, eight, nine, ten);
    return 0;
}
