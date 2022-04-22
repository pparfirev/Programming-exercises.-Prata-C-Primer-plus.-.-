#include <stdio.h>
#include <stdlib.h>
/* Напишите программу, которая выводит на экран меню, предлагающее выбрать сложение,
вычитание, умножение или деление. После выбора программа должна запросить два числа
и затем выполнить затребованную операцию. Программа должна принимать
только варианты, предлагаемые в меню. Для чисел должен использоваться
тип float и программа должна предоставлять пользователю возможность повторно
вводить числа, если он ввел нечисловые данные. В случае деления программа должна
предложить пользователю ввести другое значение, если он ввел для второго операнда
значение 0. Выполнение такой программы должно иметь примерно такой вид: */

/* Выберите желаемую операцию:
с. сложение     в. вычитание
у. умножение    д. деление
з. завершение
с
Введите первое число: 22.4
Введите второе число: один
один не является числом.
Введите число, такое как 2.5, -1.78Е8 или 3: 1
22.4 + 1 = 23.4
Выберите желаемую операцию:
с. сложение в. вычитание
у. умножение д. деление
з. завершение
д
Введите первое число: 18.4
Введите второе число: 0
Введите число, отличное от 0: 0.2
18.4 / 0.2 = 92
Выберите желаемую операцию:
с. сложение в. вычитание
у. умножение д. деление
з. завершение
s
Программа завершена. */
float get_num(void);
int main()
{

    float ans; // результат операции
    int oper; // Выбранная операция
    float n1, n2; // Числа для операции
    printf("Enter the desired operation:\na.Addition\t\tb.Subtraction\nc.Multiplication\td.Division\nq.Quit\n"); // Меню для ввода
    while((oper = getchar()) != 'q') // принимаются все значения за исключением выхода
    {
        switch(oper)
        {
            case '\n': continue; // пропуск пробела
            case 'a': printf("Enter the first number: "); // сложение
                      n1 = get_num(); // ввод чисел
                      printf("Enter the second number: ");
                      n2 = get_num();
                      ans = n1 + n2;
                      printf("%0.2f + %0.2f = %0.2f\n", n1, n2, ans); //вывод
                      break;
            case 'b': printf("Enter the first number: "); // также с вычитанием
                      n1 = get_num();
                      printf("Enter the second number: ");
                      n2 = get_num();
                      ans = n1 - n2;
                      printf("%0.2f - %0.2f = %0.2f\n", n1, n2, ans);
                      break;
            case 'c': printf("Enter the first number: "); // Умножением
                      n1 = get_num();
                      printf("Enter the second number: ");
                      n2 = get_num();
                      ans = n1 * n2;
                      printf("%0.2f * %0.2f = %0.2f\n", n1, n2, ans);
                      break;
            case 'd': printf("Enter the first number: "); // и делением
                      n1 = get_num();
                      printf("Enter the second number: ");
                      n2 = get_num();
                      while(n2 == 0) // с одним нюансом, если делитель равен нулю
                      {
                          printf("Enter the number not equal to 0: "); // то запрос на ввод нового числа
                          n2 = get_num();
                      }
                      ans = n1 / n2;
                      printf("%0.2f * %0.2f = %0.2f\n", n1, n2, ans); // вывод
                      break;
            default: printf("You must choose letters from 'a' to 'd' or 'q'\n"); //Если введена неправильная буква меню
                     break;
        }
        printf("Enter the desired operation:\na.Addition\t\tb.Subtraction\nc.Multiplication\td.Division\nq.Quit\n"); // Приглашение на повторный выбор операции
    }
    printf("Program closed.\n"); // закрытие программы
    return 0;
}


float get_num(void) // Функция ввода чисел (честно украл, самому ума не хватило сделать так элегантно)
{
    int ch; // Для вывода значения
    float input; // Входное значение
    while(scanf("%f", &input) != 1) // Если введено нечисловое значение
    {
        while((ch = getchar()) != '\n') // пропуск пробела
            putchar(ch); // Вывод введенного неверное обозначения
        printf(" is not a number.\nEnter a right number!: "); // пояснение
    }
    return input; // возврат введенного числового значения
}

