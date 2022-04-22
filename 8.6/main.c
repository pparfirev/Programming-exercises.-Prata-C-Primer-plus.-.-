#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* Модифицируйте функцию get_first () из листинга 8.8 так, чтобы она возвращала
первый встреченный непробельный символ. Протестируйте ее в какой-нибудь
простой программе. */
char get_choice();
char get_first();
int get_int();
void count(void);

int main()
{
    int choice;
    void count(void); // Объявление функции внутри main
    while((choice = get_choice()) != 'q') // Если введенный символ не равен q
    {
        switch(choice) // Условия в зависимости от выбранного пункта меню
        {
            case 'a': printf("Buy cheap and sell expensive.\n");
            break;
            case 'r': putchar('\a'); // Вывод сигнала
            break;
            case 'c': count(); // Вызов функции подсчета
            break;
            default: printf("Error!\n"); // если введен любой другой символ сообщить об ошибке (Хотя он по сути не нужен)
            break;
        }
    }
    printf("Program closed.\n");
    return 0;
}

char get_choice(void) // Функция выбора меню
{
    int ch;
    printf("Enter the letter to choose the variant:\na. advice\tr. ring\nc. count\t q. exit\n");
    ch = get_first();
    while(ch != 'a' && ch != 'r' && ch != 'c' && ch != 'q') // Если ни один символ не подходит из введенный
    {
        printf("You must choose a, r, c or q\n"); // Сообщение о неправильном вводе
        ch = get_first(); // повторный вызов функции выбора пункта
    }
    return ch; // Возврат введенного символа в меню
}

char get_first(void) // Ввод нужного символа (Принимает первый непробельный символ)
{
    int ch;
    while(isspace(ch = getchar())) // Если введенный символ пробельный
    continue; // то пропускаем его до тех пор пока не появится "непробельный"
    while(getchar() != '\n') // пропуск символа новой строки
        continue;
    return ch;
}

void count(void) // функция подсчета
{
    int n, i;
    printf("Enter the high limit for counting (int number).\n"); //приглашение на ввод предела подсчета
    n = get_int(); // Функция приема целого числа
    for(i = 1; i <= n; i++) // Подчет до введенного предела
        printf("%d\n", i); // вывод чисел до предельного значения
    while(getchar() != '\n') // пропуск символа новой строки
        continue;
}
int get_int(void) // Ввод целого числа
{
    int input;
    char ch;
    while(scanf("%d", &input) != 1) // если ввод неверный
    {
        while(scanf((ch = getchar())) != '\n')
            putchar(ch); // Отбросить символ новой строки
        printf("This is not int numb. Enter number like 4 8 15 16 or etc.\n"); // сообщить о неправильном вводе
    }
    return input; // возврат введенного числа
}
