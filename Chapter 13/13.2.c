/* Модифицируйте программу в листинге 13.1, чтобы она предлагала пользователю
ввести имя файла и читала его ответ вместе использования аргументов командной
строки. */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 255
int main(int argc, char * argv[])
{
    FILE *fp;
    FILE *in;
    char Or_filname[SIZE];
    char buffer[SIZE];
    size_t nread;
    printf("Enter the filename: ");
    gets(Or_filname); // put filename from
    if((fp = fopen(Or_filname, "rb")) == NULL)
    {
        printf("Can't open %s\n", Or_filname);
        exit(EXIT_FAILURE);
    }
    if(argc < 2) // cmd's arguments cheking
    {
        fprintf(stderr, "Using: %s name_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((in = fopen(argv[1], "wb")) == NULL) // stdinn setups
    {
        fprintf(stderr, "Can't open copying file  \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while(nread = fread(buffer, sizeof(char), sizeof(buffer), Or_filname)) // Copying data from origin file to buffer massive
        fwrite(buffer, sizeof(char), nread, argv[1]); // writing data from buffer to copy file
    fclose(fp);
    fclose(in);
    return 0;
}
