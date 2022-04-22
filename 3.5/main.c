#include <stdio.h>
#include <stdlib.h>
/* В году содержится примерно 3.156х10^7 секунд. Напишите программу, которая
предлагает ввести возраст в годах, а затем выводит на экран эквивалентное значение
в секундах. */
int main()
{
    int age;
    float yins = 3.156e+7;
    printf("Enter your age in years:");
    scanf("%d", &age);
    float ageins = age * yins;
    printf("Ypur age in seconds is: %e", ageins);
    return 0;
}
