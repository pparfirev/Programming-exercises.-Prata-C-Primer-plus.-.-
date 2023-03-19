/* Напишите функцию, которая принимает три аргумента: имя отсортированного
массива целых чисел, количество элементов в массиве и целое число, которое
можно найти. Функция возвращает значение 1, если целое число присугствует в
массиве, и 0 — если отсугствует. Воспользуйтесь двоичным поиском. */
#include <stdio.h>
#include <stdlib.h>
int array(const int sorted[], int size, int val);
#define SIZE 10

int main()
{
    int nums[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num;
    int found;

    printf("Enter an integer to search for: ");
    while(scanf("%d", &num) == 1)
    {
        found = inarray(nums, SIZE, num);
        printf("%d %s in the array.\n", num, found? "is" : "isn't");
        printf("Next value (q to quit): ");
    }
    printf("Program Closed\n");
    return 0;
}
int inarray(const int sorted[], int size, int val)
{
    int min = 0;
    int max = size - 1;
    int mid;
    int found = 0;

    while(min < max)
    {
        mid = (min + max) / 2;
        if(val < sorted[mid])
            max = mid - 1;
        else if(val > sorted[mid])
            min = mid + 1;
        else
        {
            found = 1;
            break;
        }
    }
    if(sorted[min] == val)
        found = 1;
    return found;
}
