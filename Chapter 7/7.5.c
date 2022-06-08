#include <stdio.h>
#include <stdlib.h>
/* Выполните упражнение 4, но с применением оператора switch */
int main()
{
    char ch;
    int change = 0; // Количество замен
       while((ch = getchar()) != '#') // Цикл продолжается пока не будет введен #
    {
        switch(ch) // оператор условия
        {
            case '.': ch = '!'; // то меняем символ на !
                      change++;
                      putchar(ch);
                      break;
            case '!': change++; // Если ch !
                      putchar(ch); // То дважды выводим его
                      putchar(ch);
                      break;
            default: putchar(ch); // то просто выводим его
    }
    }
    printf("\nTotally have %d changes.\n", change);
    return 0;
}
