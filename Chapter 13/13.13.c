/* Выполните упражнение 12, используя массивы переменной длины вместо стандартных
массивов. */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 255
#define X 20
#define Y 30
void mas_ch(int x, int y, int masin[x][y], char masout[x][y + 1]);
int main()
{
    int x, y;
    x = X;
    y = Y;
    int mas[X][Y];
    char masout[X][Y + 1];
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

        for(int x = 0; x < X; x++)
            for(int y = 0; y < Y; y++)
            fscanf(fp, "%d", &mas[x][y]); // put numbers from file to a massive

       /* for(int x = 0; x < 20; x++) // code for checking create massive
        {
            putchar('\n');
            for(int y = 0; y < 30; y++)
            printf("%d ", mas[x][y]);
        } */
    mas_ch(x, y, mas, masout);

        for(int x = 0; x < X; x++) // put a zero symbol to every 31-st y value of masout
            masout[x][Y] = '\0';
        for(int x = 0; x < X; x++)  // Showing masout content
        {
            putchar('\n');
            for(int y = 0; y < (Y + 1); y++)
            printf("%c ", masout[x][y]);
        }

    fclose(fp);
    return 0;
}

mas_ch(int x, int y, int masin[x][y], char masout[x][y + 1])
{
    for(int col = 0; col < x; col++)
        {
            for(int row = 0; row < y; row++) // put different char to a masout depending value of element of mas
            switch(masin[col][row])
        {
            case 0: masout[col][row] = ' ';
            break;
            case 1: //putchar('.');
                    masout[col][row] = '.';
            break;
            case 2: //putchar('\'');
                    masout[col][row] = '\'';
            break;
            case 3: //putchar(':');
                    masout[col][row] = ':';
            break;
            case 4: //putchar('~');
                    masout[col][row] = '~';
            break;
            case 5: //putchar('*');
                    masout[col][row] = '*';
            break;
            case 6: //putchar('=');
                    masout[col][row] = '=';
            break;
            case 7: //putchar('+');
                    masout[col][row] = '+';
            break;
            case 8: //putchar('%');
                    masout[col][row] = '%';
            break;
            case 9: //putchar('#');
                    masout[col][row] = '#';
            break;
            default: //putchar(' ');
                    masout[col][row + 1] = ' ';
            break;
        }
        }
}
