/* Текстовый файл содержит информацию о команде по софтболу (разновидность
бейсбола). В каждой строке данные упорядочены следующим образом:
4 Джесси Джойбет 5 2 1 1
Первым членом является номер игрока (обычно это число из диапазона 0-18).
Второй член — это имя игрока, а третий — его фамилия. Каждое имя состоит из
одного слова. Следующий член показывает, сколько раз игрок принимал мяч, за
которым следует количество нанесенных игроком ударов, проходов и засчитанных
пробежек. Файл может содержать результаты более чем одной игры, следовательно,
для одного и того же игрока может быть несколько строк. Напишите
программу, которая сохраняет соответствующие данные в массиве структур.
Структура должна состоять из членов, в которых представлены фамилия и имя,
количество набранных очков, проходов и засчитанных пробежек, а также средний
результат (эти значения вычисляются позже). В качестве индекса массива
можете использовать номер игрока. Программа должна выполнять чтение до
конца файла, и накапливать итоговые результаты по каждому игроку.
Мир статистики бейсбола довольно сложен. Например, проход или взятие базы
в результате ошибки не расценивается так же высоко, как тот же самый результат,
полученный за счет меткого удара, однако он позволяет получить выигранную
пробежку. Но эта программа должна только читать и обрабатывать файлы
данных, как описано ниже, не заботясь о реалистичности данных.
Простейший способ предусматривает инициализацию содержимого структуры
нулями, чтение данных из файла во временные переменные и затем их добавление
к содержимому соответствующей структуры. После того, как программа завершит
чтение файла, она должна вычислить средний уровень достижений для
каждого игрока и запомнить его в соответствующем члене структуры. Средний
уровень достижений вычисляется путем деления накопленного числа ударов, выполненных
игроком, на количество выходов на ударные позиции; вычисление
должно быть с плавающей запятой. Затем программа должна отобразить накапливаемые
данные по каждому игроку наряду со строкой, в которой содержатся
суммарные статистические данные по всей команде. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 30
#define MAS 19
struct players
{
    char name[LEN];
    char sname[LEN];
    int bats;
    int hints;
    int run;
    int rbi;
    float mid;
};
int main()
{

    struct players list[MAS];

    FILE *fplayer;
    int count = 0;
    int index, filecount;
    int size = sizeof(struct players);
    if((fplayer = fopen("list.txt", "r")) == NULL) // open file of player's statictics
    {
        fputs("Can't open file list.txt", stderr);
        exit(1);
    }

    for(int n = 0; n < MAS; n++) // making all number elements of massive zero
    {
        list[n].bats = 0;
        list[n].hints = 0;
        list[n].run = 0;
        list[n].rbi = 0;
        list[n].mid = 0.0;
    }
    char name[LEN];
    char sname[LEN];
    int bats = 0;
    int hints = 0;
    int run = 0;
    int rbi = 0;
    while(fscanf(fplayer, "%d %s %s %d %d %d %d", &index, name, sname,
          &bats, &hints, &run, &rbi) == 7) // scanning data from file
          {
              for(int n = 0; n < MAS; n++)
              {
                  if(n == index) // if massive index equal to number of player
                  {
                      list[index].bats += bats;
                      list[index].hints += hints;
                      list[index].run += run;
                      list[index].rbi += rbi;
                  }
              }
             strcpy(list[index].name, name); // Copying name and surname from temporary massives
             strcpy(list[index].sname, sname);
              list[index].mid = (float)list[index].hints / list[index].bats;
          }
          float sbats = 0, shints = 0, srun = 0, srbi = 0, smid = 0; // creating middle statistics of all players
          for(int n = 0; n < MAS; n++)
          {
              if(list[n].bats != 0 && list[n].hints != 0) // Dropping null values
             {
                 printf("%d %s %s %d %d %d %d %.2f\n", n, list[n].name, list[n].sname, // show strcuture's elements
          list[n].bats, list[n].hints, list[n].run, list[n].rbi, list[n].mid);
                count++; //counting quality of players for middle value
              }
              sbats += list[n].bats;
              shints += list[n].hints;
              srun += list[n].run;
              srbi += list[n].rbi;
              smid += list[n].mid;
          }
          printf("The middle quality of stats:\n"); // Out middle value statistics of all team
          printf("bats = %.2f, hints = %.2f, run = %.2f, RBI = %.2f, Mid = %.2f\n",
                 sbats / count, shints / count, srun / count, srbi / count, smid / count);

    return 0;
}
