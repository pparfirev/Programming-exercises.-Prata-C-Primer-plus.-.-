/* Разработайте и протестируйте функцию, которая читает первое слово из строки
ввода в массив и отбрасывает ос^тальную часть строки. Функция должна пропускать
ведущие пробельные символы. Определите слово как последовательность
символов, не содержащую символов пробела, табуляции или новой строки.
Используйте функцию getchar(), а не scanf(). */
#include <stdio.h>
#include <stdlib.h>
#define LEN 40
char *enter_n(char *str, int n);
int main()
{
    char mas[LEN];
    char *line;
    printf("Enter the text for saving in massive:\n");
    line = enter_n(mas, LEN);
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
