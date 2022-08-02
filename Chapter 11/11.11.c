/* Ќапишите программу, котора€ читает до 10 строк и или до по€влени€ EOF, в
зависимости от того, что произойдет раньше. ‘ункци€ должна предложить
пользователю меню с п€тью вариантами: вывод исходного списка строк, вывод
строк согласно последовательности сопоставлени€ ASCII, вывод строк в пор€дке
возрастани€ длины, вывод строк в пор€дке возрастани€ длины первого слова
в строке и выход из программы. ћеню должно отображатьс€ до тех пор, пока
пользователь не выберет вариант выхода из программы. ѕрограмма должна
действительно выполн€ть запрошенные действи€. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 81
char *s_gets(char *st, int n);
void stsrt(char *strings[], int num); // Function of sorting strings by ASCII
void lensort(char *strings[], int num); // By string length
void lenword(char *strings[], int num); // By first word's length in string
int main()
{
    char input[10][SIZE];
    char *ptstr[10]; // Massive for pointer variables
    int ct = 0; // Entering counter
    int k; // Output counter
    char choice;
    printf("Enter up to 10 strings, and they'll be sorted\n");
    printf("For stopping enter, press enter button at the start of the string.\n");
    while(ct < 10 && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct]; // Setting pointer om strings
        ct++;
    }
    puts("Choose the menu:");
    puts("a. Displaying list");
    puts("b. Displaying according to ASCII sequence");
    puts("c. Displaying in ascending order of length");
    puts("d. Displaying in ascending order of length of a first word");
    puts("q. Exit the program");
    while((choice = getchar()) != EOF)
    {
       while(getchar() != '\n')
            continue;
       switch(choice)
       {
           case 'a': for(k = 0; k < ct; k++)
                     puts(input[k]); // Sorted pointers
                     break;
           case 'b': stsrt(ptstr, ct); // Strings sorter
                     for(int k = 0; k < ct; k++)
                     puts(ptstr[k]);
                     break;
           case 'c': lensort(ptstr, ct);
                     for(int k = 0; k < ct; k++)
                     puts(ptstr[k]);
                     break;
           case 'd': lenword(ptstr, ct);
                     for(int k = 0; k < ct; k++)
                     puts(ptstr[k]);
                     break;
           case 'q': puts("Program closed");
                     return 0;
           default: puts("Enter from a to d, or press q to exit");
                    break;
       }
    puts("Choose the menu:");
    puts("a. Displaying list");
    puts("b. Displaying according to ASCII sequence");
    puts("c. Displaying in ascending order of length");
    puts("d. Displaying in ascending order of length of a first word");
    puts("q. Exit the program");
    }
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin); // ввод строки с клавиатуры
    if(ret_val) // если строка введена
    {
        while(st[i] != '\n' && st[i] != '\0') // инкремент до конца строки или символа новой строки
            i++; // инкремент счетчика
        if(st[i] == '\n') // если введен символ новой строки
            st[i] = '\0'; // то вводитс€ символ окончани€ строки
        else // “ребуетс€ наличие words[i] == '\0'
            while(getchar() != '\n')
            continue;
    }
    return ret_val;
}
void stsrt(char *strings[], int num) // Function of sorting strings pointers
{
    char *temp;
    int top, seek;
    for(top = 0; top < num - 1; top++)
        for(seek = top + 1; seek < num; seek++)
        if(strcmp(strings[top], strings[seek]) > 0)
    {
        temp = strings[top];
        strings[top] = strings[seek];
        strings[seek] = temp;
    }
}
void lensort(char *strings[], int num)
{
    char *temp;
    int top, seek;
    for(top = 0; top < num - 1; top++)
        for(seek = top + 1; seek < num; seek++)
        if(strlen(strings[top]) > strlen(strings[seek]))
    {
        temp = strings[top];
        strings[top] = strings[seek];
        strings[seek] = temp;
    }
}
void lenword(char *strings[], int num)
{
    int k, l;
    char *temp;
 for(int top = 0; top < num - 1; top++)
    {
        for(int seek = top + 1; seek < num; seek++)
        {
            for(l = 0; !(isspace(strings[top][l])); ++l)
            {
                continue;
            }
            for(k = 0; !(isspace(strings[seek][k])); ++k)
            {
                continue;
            }
            if(k < l)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }
}
