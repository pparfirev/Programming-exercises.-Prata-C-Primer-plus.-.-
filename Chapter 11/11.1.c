/* –азработайте и протестируйте функцию, котора€ измекает из ввода следующие
n символов (включа€ символы пробела, табул€ции и новой строки), сохран€€
результаты в массиве, адрес которого передаетс€ в качестве аргумента. */
#include <stdio.h>
#include <stdlib.h>
#define LEN 40
char *enter_n(char *str, int n);
int main()
{
    char mas[LEN];
    char *line;
    int quality = 0;
    printf("Enter the quality of symbols to enter: \n");
    scanf("%d", &quality);
    printf("Enter the text for saving in massive:\n");
    line = enter_n(mas, quality + 1); // Counting starts since 0, so we need increase quality
    puts(line);
    return 0;
}
char *enter_n(char *str, int n)
{
    int i = 0, ch;
    for(i = 0; i < n; i++)
    {
        ch = getchar();
        if(ch != EOF)
            str[i] = ch;
        else
            break;
    }
   return str;

}
