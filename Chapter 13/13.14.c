/* Цифровые изображения, особенно передаваемые по радиоканалу космическим
аппаратом, могут содержать помехи. Добавьте в программу из упражнения 12
функцию подавления помех. Она должна сравнивать каждое значение с соседним
и значениями, расположенными слева и справа, снизу и сверху. Если значение
отличается более чем на 1 от своих соседей, оно должно быть заменено средним
значением всех соседних величин. Среднее значение должно быть округлено до
ближайшего целого. Обратите внимание, что точки, находящиеся на границах,
имеют меньше четырех соседей, поэтому они требуют специальной обработки. */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 255
void filter(int massive[20][30]);
int main()
{
    int mas[20][30];
    char masout[20][31];
    FILE *fp;
    int ch;
    char filename[SIZE];
    printf("Enter the filename: ");
    gets(filename); // put filename from

    if((fp = fopen(filename, "r")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
        for(int x = 0; x < 20; x++)
            for(int y = 0; y < 30; y++)
            fscanf(fp, "%d", &mas[x][y]); // put numbers from file to a massive
        filter(mas);
       /* for(int x = 0; x < 20; x++) // code for checking create massive
        {
            putchar('\n');
            for(int y = 0; y < 30; y++)
            printf("%d ", mas[x][y]);
        } */

        for(int x = 0; x < 20; x++)
        {
            //putchar('\n');
            for(int y = 0; y < 30; y++) // put different char to a masout depending value of element of mas
            switch(mas[x][y])
        {
            case 0: //putchar(' ');
                    masout[x][y] = ' ';
            break;
            case 1: //putchar('.');
                    masout[x][y] = '.';
            break;
            case 2: //putchar('\'');
                    masout[x][y] = '\'';
            break;
            case 3: //putchar(':');
                    masout[x][y] = ':';
            break;
            case 4: //putchar('~');
                    masout[x][y] = '~';
            break;
            case 5: //putchar('*');
                    masout[x][y] = '*';
            break;
            case 6: //putchar('=');
                    masout[x][y] = '=';
            break;
            case 7: //putchar('+');
                    masout[x][y] = '+';
            break;
            case 8: //putchar('%');
                    masout[x][y] = '%';
            break;
            case 9: //putchar('#');
                    masout[x][y] = '#';
            break;
            default: //putchar(' ');
                    masout[x][31] = ' ';
            break;
        }
        }
        for(int x = 0; x < 20; x++) // put a zero symbol to every 31-st y value of masout
            masout[x][30] = '\0';
        for(int x = 0; x < 20; x++)  // Showing masout content
        {
            putchar('\n');
            for(int y = 0; y < 31; y++)
            printf("%c ", masout[x][y]);
        }

    fclose(fp);
    return 0;
}
void filter(int massive[20][30])
{
    double total = 0;
	int count = 0;
    for(int x = 0; x < 20; x++)
            for(int y = 0; y < 30; y++)
            {
                if(x + 1 < 20) // Right border
                {
                    if(abs(massive[x][y] - massive[x + 1][y]) <= 1)
                        continue;
                total += massive[x + 1][y];
                count++;
                }

                if(y + 1 < 30) // Down border
                {
                    if(abs(massive[x][y] - massive[x][y + 1]) <= 1)
                        continue;
                total += massive[x][y + 1];
                count++;
                }

                if(x > 0) // Left border
                {
                    if(abs(massive[x][y] - massive[x - 1][y]) <= 1)
                        continue;
                total += massive[x - 1][y];
                count++;
                }
                if(y > 0) // upper border
                {
                    if(abs(massive[x][y] - massive[x][y - 1]) <= 1)
                        continue;
                total += massive[x][y - 1];
                count++;
                }
                massive[x][y] = (int) rint(total / count);
            }
}
