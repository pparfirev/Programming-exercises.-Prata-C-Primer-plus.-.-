/* Напишите программу, которая принимает в качестве аргументов командной
строки символ и ноль или более имен файлов. Если за символом не следуют аргументы,
программа должна читать стандартный ввод. В противном случае она
должна открывать каждый файл по очереди и сообщать, сколько раз в нем ветре-
чается указанный символ. Вместе с результатом каждого подсчета должны быть
указаны имя файла и сам символ. Предусмотрите средства проверки ошибок,
позволяющие выяснить корректность количества аргументов и возможность открытия
файлов. Если файл не может быть открыт, программа должна сообщать
об этом факте и переходить к обработке следующего файла. */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 255

int main(int argc, char * argv[])
{
    int ch;
    FILE *fp;
    int symb_count = 0;
    int n = 0;
    char filename[SIZE];
        if(argc == 1) // if no arguments in CommandLine
        {
            printf("Using: %s name_file\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    else if(argc == 2) // if we have only symbol argument in command line
    {
        printf("Enter the filename: (or press q to exit) ");
        while(gets(filename))
        {
            if((fp = fopen(filename, "rb")) == NULL)
            {
            printf("Can't open %s\n", filename); // Exit from Cycle if entered wrong filename
            exit(EXIT_FAILURE);
            }
                while((ch = getc(fp)) != EOF)
                {
                    if(ch == argv[1][0]) // if char equal to symbol from command line
                    symb_count++; // increase the symbol counter
                }
            printf("File %s has %d %s symbols\n", filename, symb_count, argv[1]);
            printf("Enter the new filename: (or press q to exit) ");
            symb_count = 0; // after counting set var to zero
        }
    }
    else if (argc > 2) // if we have filenames in command line
    {
        for(int n = 2; n <= argc - 1; n++) // Using cycle to check every file
        {
            if((fp = fopen(argv[n], "rb")) == NULL)
        {
            printf("Can't open %s\n", argv[n]);
            exit(EXIT_FAILURE);
        }
            while((ch = getc(fp)) != EOF) // same cycle for checking symbol
            {
                if(ch == argv[1][0])
                symb_count++;
            }
            printf("File \"%s\" has %d %s symbols\n", argv[n], symb_count, argv[1]);
            symb_count = 0;
        }

    }
    fclose(fp);
    return 0;
}
