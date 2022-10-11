/* Модифицируйте программу в листинге 13.6, чтобы вместо интерактивного интерфейса
она использовала интерфейс командной строки. */
/* randbin.c — произвольный доступ, двоичный ввод-вывод */
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main(int argc, int * argv[])
{
    double numbers[ARSIZE];
    double value;
    const char *file = "numbers.dat";
    int i;
    int num = atoi(argv[1]); // number from command line arguments
    long pos;
    FILE *iofile;
    for(i = 0; i < ARSIZE; i++) // Creating set of double variables
        numbers[i] = 100.0 * i + 1.0 / (i + 1);
    if((iofile = fopen(file, "wb")) == NULL) // Trying to open file
    {
        fprintf(stderr, "Can't open file %s for output.\n", file);
        exit(EXIT_FAILURE);
    }
    fwrite(numbers, sizeof(double), ARSIZE, iofile); // Writing massive in file in binary format
    fclose(iofile);
    if((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Can't open file %s for random access.\n", file);
        exit(EXIT_FAILURE);
    }
    if(num >= 0 && num < ARSIZE)
    {
        pos = (long) num * sizeof(double); // Offset calculation
        fseek(iofile, pos, SEEK_SET); // Move to desired position
        fread(&value, sizeof(double), 1, iofile);
        printf("At this index has value %f.\n", value);
    }
    fclose(iofile); // Ending
    puts("Program Closed.");
    return 0;
}
