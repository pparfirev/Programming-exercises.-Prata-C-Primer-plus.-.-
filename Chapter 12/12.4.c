/* Напишите и протестируйте в цикле функцию, которая возвращает количество
ее вызовов. */
#include <stdio.h>
#include <stdlib.h>
static int loop_count = 0;
int loop(void);
int main()
{
    int n = 1;
    while(n < 10)
    {
        loop_count = loop();
        n++;
    }
    printf("Quality of loops is %d\n", loop_count);
    return 0;
}
int loop(void)
{
    return ++loop_count;
}
