#include <stdio.h>
#include <stdlib.h>
/*Напишите программу, которая запрашивает имя пользователя и его фамилию.
Сделайте так, чтобы она выводила введенные имена в одной строке и количество
символов в каждом слове в следующей строке. Выровняйте каждое количество
символов по окончанию соответствующего имени, как показано ниже:
Иван Петров
   4      6
Затем сделайте так, чтобы программа выводила ту же самую информацию, но с
количеством символов, выровненным по началу каждого слова:
Иван Петров
4    6     */
int main()
{
    char name[30], surname[30];
    printf("Enter your name:\n");
    scanf("%s", name);
    printf("Enter your surname:\n");
    scanf("%s", surname);
    printf("%s %s\n%*d %*d\n", name, surname, strlen(name), strlen(name), strlen(surname), strlen(surname));
    printf("%s %s\n%-*d %-*d", name, surname, strlen(name), strlen(name), strlen(surname), strlen(surname));
    return 0;
}
