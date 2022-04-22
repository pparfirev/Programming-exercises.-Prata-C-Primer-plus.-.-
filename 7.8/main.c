#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age = 20;
    while(age++ <= 65)
    {
        if((age % 20) == 0)
            printf("%d\n", age);
        if(age == 65)
           printf("%d\n", age);
    }
    return 0;
}
