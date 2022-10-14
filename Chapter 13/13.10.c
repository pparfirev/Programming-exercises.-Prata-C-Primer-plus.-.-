/* Напишите программу, открывающую текстовый файл, имя которого получается
интерактивно. Организуйте цикл, который предлагает пользователю ввести позицию
в файле. Затем программа должна вывести часть файла, начиная с этой
позиции и заканчивая следующим символом новой строки. Цикл ввода должен
завершаться при вводе отрицательного дли нечислового значения. */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 255
int main()
{
    FILE *fp; // file pointer
    char ch;
    unsigned long count = 0;
    char filename[SIZE]; // Massive for entering filename
    int pos;
    printf("Enter the filename: ");
    gets(filename); // put filename from

    if((fp = fopen(filename, "rb")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    printf("Now, enter the text position (or enter negative or non integer value to exit):  ");
    while(scanf("%d", &pos) == 1 && pos >= 0)
    {
        fseek(fp, pos, SEEK_SET); // Enter the position in file that we choose
        while((ch = getc(fp)) != EOF && ch != '\n') // Until to the end of the file or newline
            putchar(ch);
        putchar('\n'); // after entered text enter newline symbol
        printf("Now, enter the new text position (or enter negative or non integer value to exit):  ");
    }
    fclose(fp);
    return 0;
}
