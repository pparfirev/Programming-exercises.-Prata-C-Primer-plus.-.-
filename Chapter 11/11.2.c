/* Модифицируйте и протестируйте функцию из упражнения 1, обеспечив в ней
прекращение ввода после n символов либо при достижении первого символа
пробела, табуляции или новой строки, в зависимости от того, что произойдет
раньше. (Не ограничивайтесь только использованием scanf ().) */
#include <stdio.h>
#include <stdlib.h>
#define LEN 40
char *enter_n(char *str, int n);
int main()
{
    char mas[LEN];
    char *line;
    int quality = 5;
    printf("Enter the quality of symbols to enter: \n");
    scanf("%d", &quality);
    scanf("%*1[\n]"); // skip '\n' symbol
    printf("Enter the text for saving in massive:\n");
    line = enter_n(mas, quality + 1); // Counting starts since 0, so we need increase quality
    puts(line);
    return 0;
}
char *enter_n(char *str, int n)
{
    int i = 0, ch = 0;
    for(i = 0; i < n; i++)
    {
        ch = getchar();
        if(ch != EOF)
            str[i] = ch;
        else
            break;
        if(isspace(ch))
           break;
    }
   return str;

}
