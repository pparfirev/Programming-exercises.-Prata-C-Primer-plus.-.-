/* Библиотека ANSI содержит функцию clock () со следующим описанием:

#include <time.h>
clock_t clock (void);

Здесь clock_t — тип данных, определенный в файле time.h. Функция возвращает
процессорное время, выраженное в единицах, которые зависят от реализации.
(Если процессорное время недоступно или не может быть представлено,
функция возвращает -1.) Однако в файле time.h также определена константа
CLOCKS_PER_SEC, которая представляет количество единиц процессорного времени
в секунде. Следовательно, в результате деления разницы между двумя значениями,
возвращаемыми clock(), на константу CLOCKS_PER_SEC получается
количество секунд, прошедшее между двумя вызовами функции. Приведение
значений к типу double до операции деления позволит получить результат в
долях секунды. Напишите функцию, которая принимает аргумент типа double,
представляющий промежуток времени, а затем выполняет цикл до истечения
указанного периода времени. Напишите простую программу для тестирования
этой функции. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t clock(void);
void interval(double);

int main()
{
    double time_c;
    printf("Enter the choose time delay in seconds: ");
    scanf("%lf", &time_c);
    clock_t start, stop;
    start = clock(); // Time starting
    interval(time_c); // Delay function
    stop = clock();
    printf("The delay is %.2lf second.\n", ((double) stop - start) / CLOCKS_PER_SEC);
    return 0;
}
void interval(double t)
{
    clock_t begin, end;
    begin = clock(); // starting time
    do
    {
        end = clock(); // ending time
    }while(((double)end - begin) / CLOCKS_PER_SEC < t); // Cycle is going until time is less that entering delay t
}
