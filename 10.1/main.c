/* ћодифицируйте программу rain.с из листинга 10.7, чтобы она выполн€ла вычислени€
с использованием указателей вместо индексов. (¬ам по-прежнему придетс€
объ€вл€ть и инициализировать массив.) */
#include <stdio.h>
#include <stdlib.h>
#define MONTHS 12 //  оличество мес€цев в году
#define YEARS 5 // количество лет, дл€ которых доступны данные

int main()
{
    const float rain[YEARS][MONTHS] =  // »нициализаци€ данными об осадках за период с 2010 по 2014 гг.
    {
      {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
      {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
      {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
      {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
      {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    int year, month;
    float subtot, total;
    printf(" YEAR    QUALITY OF RAIN (INCHES)\n");
    for(year = 0, total = 0; year < YEARS; year++)
    { // ƒл€ каждого года суммировать количество осадков за каждый мес€ц
        for(month = 0, subtot = 0; month < MONTHS; month++)
        subtot += *(*(rain + year) + month); // ќбработка каждого мес€ца
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot; // ќбща€ сумма дл€ всех лет // ќбработка каждого года
    }
    printf("\nMiddle year quality of rain is %.1f inches.\n", total / YEARS);
    printf("MIDDLE MONTH QUALITY OF RAIN:\n\n");
    printf("Jan FEB MAR APR MAY JUN JUL AUG SEP OCT NOV DEC\n");
    for(month = 0; month < MONTHS; month++)
    { // ƒл€ каждого мес€ца суммировать количество осадков на прот€жении годов
        for(year = 0, subtot = 0; year < YEARS; year++)
            subtot += *(*(rain + year) + month); // ќбработка каждого года
        printf("%3.1f ", subtot / YEARS);
    }
    printf("\n");
    return 0;
}
