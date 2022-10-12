/* Напишите программу, которая открывает два файла. Получать имена файлов
можно либо через командную строку, либо предложив пользователю ввести их.
    а. Сделайте так, чтобы эта программа выводила строку 1 первого файла, строку 1
второго файла, строку 2 первого файла, строку 2 второго файла и т.д., пока не
будет выведена последняя строка более длинного (по количеству строк) файла.
    б. Модифицируйте программу так, чтобы строки с одним и тем же номером выводились
в одной экранной строке. */
#include <stdio.h>
#include <stdlib.h>
#define LEN 25

int main()
{
    FILE *first, *sec; // two pointers on FILE
    int ch;
    char First_filename[LEN];
    char Sec_filename[LEN];
    char name[LEN]; // place for output name file
    int Newline_count = 0;
    printf("Enter the first filename: ");
    gets(First_filename); // put filename from
    if((first = fopen(First_filename, "rb")) == NULL) // stdinn setups
    {
        fprintf(stderr, "Can't open file \"%s\"\n", First_filename);
        exit(EXIT_FAILURE);
    }
    printf("Enter the second filename: ");
    gets(Sec_filename); // put filename from
    if((sec = fopen(Sec_filename, "rb")) == NULL) // stdinn setups
    {
        fprintf(stderr, "Can't open file \"%s\"\n", Sec_filename);
        exit(EXIT_FAILURE);
    }
    char ch1 = getc(first);
    char ch2 = getc(sec);
    while(ch1 != EOF || ch2 != EOF)
    {
    while((ch1 != EOF) && (ch1 != '\n'))
    {
        putchar(ch1); //same as putchar(ch)
        ch1 = getc(first);
    }
    if(ch1 != EOF)
    {
        putchar('\n');
        ch1 = getc(first);
    }
    while((ch2 != EOF) && (ch2 != '\n'))
    {
        putc(ch2, stdout); //same as putchar(ch)
        ch2 = getc(sec);
    }
    if(ch2 != EOF)
    {
        putchar('\n');
        ch2 = getc(sec);
    }
    }
    fclose(first);
    fclose(sec);
    return 0;
}
