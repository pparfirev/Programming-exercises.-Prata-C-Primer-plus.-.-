#include <stdio.h>
#include <stdlib.h>
/* 10. Обобщите функцию to_binary( ) из листинга 9.8 до функции to_base_n( ) , которая
принимает второй аргумент в диапазоне от 2 до 10. Она должна выводить
число, переданное в первом аргументе, в системе счисления с основанием, которое
указано во втором аргументе. Например, вызов to_base_n(129,8) должен
отобразить 201, т.е. восьмеричный эквивалент числа 129. Протестируйте готовую
функцию в какой-нибудь программе. */
void to_binary(unsigned long n);
void to_base_n(unsigned long b, unsigned q);
int main()
{
    unsigned long number;
    unsigned syst;
    printf("Enter the the int value or press q for exit: \n");
    while(scanf("%lu", &number) == 1)
    {
        printf("And number system (from 2 to 10): ");
        scanf("%u", &syst);
        if(syst < 2 || syst > 10)
        {
            printf("You must enter the second number between 2 and 10.\nEnter the first number again: ");
            continue;
        }
        printf("Number in %lu system number is: ", syst);
            to_base_n(number, syst);
            putchar('\n');
            printf("Enter next  int value or press q for exit: \n");
    }
    printf("program closed.\n");
    return 0;
}

void to_base_n(unsigned long b, unsigned q) //b-число;q-цифра обозначающая систему счисления.
{
    int r;
    r = b % q;
    if(b >= q)
        to_base_n(b / q, q);
    printf("%u", r);
}
