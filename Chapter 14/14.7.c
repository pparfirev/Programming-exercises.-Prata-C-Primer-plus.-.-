/* Модифицируйте код в листинге 14.14 так, чтобы каждая запись читалась из файла
и отображалась, чтобы была возможность удалить запись, и можно было изменить
ее содержимое. Если вы удаляете запись, используйте освободившуюся
позицию массива для чтения следующей записи. Чтобы разрешить изменение существующего
содержимого, вместо режима "а+Ь" необходимо применять "r+b" и уделять больше внимания
установке указателя в файле, не допуская перезаписывание
существующих записей добавляемыми записями. Проще всего внести
все изменения в данные, хранящиеся в памяти, и затем записать всю финальную
информацию в файл. Один из возможных подходов к отслеживанию изменений
предполагает добавление в структуру каталога члена, который указывает, должен
ли он быть удален. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 // Maximum books quality
char *s_gets(char *st, int n);
struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
int main()
{
    struct book library[MAXBKS]; // structure massive
    int count = 0;
    int index, filecount;
    FILE *pbooks;
    int size = sizeof(struct book);
    if((pbooks = fopen("book.txt", "r+b")) == NULL)
    {
        fputs("Can't open file book.txt", stderr);
        exit(1);
    }
    rewind(pbooks); // Go at the start of file
    while(count < MAXBKS && fread(&library[count],
                                  size, 1, pbooks) == 1)
    {
        if(count == 0)
            puts("Now file book.txt has: ");
        printf("%s author %s: $%.2f\n", library[count].title,
               library[count].author, library[count].value);
               count++;
    }
    filecount = count;
    if(count == MAXBKS)
    {
        fputs("File book.txt is full", stderr);
        exit(2);
    }
    char ent[MAXTITL];
    char temp[MAXTITL];
    int del;
    int del_c = 0;
    char delch = '\0';
    puts("Choose the book name for editing or delete: ");
    puts("Or Enter empty string to stop entering and exit");
    while(s_gets(ent, MAXTITL) != NULL && ent[0] != '\0')
    {
       // printf("%s", ent);
        for(int n = 0; n < count; n++)
        {

            if(strcmp(library[n].title, ent) == 0)
            {
                puts("What would you do with this book?");
                puts("Enter \"0\" for delete or \"1\" for editing");
                    scanf("%d", &del);
                    while(getchar() != '\n')
                                continue;
                    if(del == 1)
                    {
                        puts("Enter new title of book: ");
                        s_gets(library[n].title, MAXTITL);
                        puts("Enter name of author");
                        s_gets(library[n].author, MAXAUTL);
                        puts("Enter the price of book: ");
                        scanf("%f", &library[n].value);
                                while(getchar() != '\n')
                                continue; // ÑleanUp enter string
                    }
                    if(del == 0)
                    {
                        for(int y = n; y < count; y++)
                        {
                            if(y + 1 != count)
                            library[y] = library[y + 1];

                        }
                        count--;
                        del_c++;
                    }
            }
        }
        puts("Enter another name of a book");
        puts("or empty string for exit: ");
       continue;
    }
    if(count > 0)
    {
        puts("Catalog of your books");
        for(index = 0; index < count; index++)
             printf("%s author %s: $%.2f\n", library[index].title,
               library[index].author, library[index].value);
               rewind(pbooks);
        fwrite(&library[0], size, count, pbooks);
        fwrite(&library[filecount], size, del_c, pbooks);
    }
    else
        puts("Now books? Very Sad.\n");
    puts("Program Closed\n");
    fclose(pbooks);
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n'); // NewLine finding
        if(find) // If address not equal NULL
            *find = '\0'; // place zero symb here
        else
            while(getchar() != '\n')
            continue; // drop the NewLine symb
    }
    return ret_val;
}
