/* Напишите и протестируйте функцию Fibonacci(), в которой для вычисления
чисел Фибоначчи вместо рекурсии применяется цикл. */
#include <stdio.h>
#include <stdlib.h>
void fibonacci(unsigned n);
int main()
{
    unsigned num;
    printf("Enter the number to count Fibonacci number: (or press q to quit)\n");
    while(scanf("%u", &num) == 1)
    {
     fibonacci(num);
     printf("Enter the number to count Fibonacci number: (or press q to quit)\n");
    }
    return 0;
}

void fibonacci(unsigned n)
{
    unsigned n1 = 1, n2 = 1, n_sum;
    unsigned count;
             for(count = 0; count <= n - 1; count++)
             {
                  if(count < 2)
                  printf("1 ");
        else
        {
       n_sum = n1 + n2; // Число равно сумме предыдущих
       n1 = n2;
       n2 = n_sum;
       printf("%u ", n_sum);
        }
    }
    return;
}
