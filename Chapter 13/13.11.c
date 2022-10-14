/* Напишите программу, которая принимает два аргумента командной строки.
Первый аргумент - это строка, а второй - имя файла. Программа должна искать
в файле и выводить все строки, содержащие указанную. Поскольку задача
ориентирована на строки, а не на символы, используйте функцию fgets()
вместо getc(). Для поиска строки, содержащей заданную, применяйте функцию
strstr() (кратко описанную в упражнении 7 из главы 11) из стандартной библиотеки С. */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 255
int main(int argc, char *argv[])
{
    FILE *fp;
    char Line[SIZE];
    char filename[SIZE];
    if(argc != 3)
    {
        printf("Using: %s name_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while(fgets(Line, SIZE, fp) != NULL) // Put line from file to buffer massive
    {
        if(strstr(Line, argv[1]) != NULL) // if buffer line include line from CommandLine
            printf("%s", Line); // Print that Line
    }
    fclose(fp);
    return 0;
}
