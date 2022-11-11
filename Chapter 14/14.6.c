/* ��������� ���� �������� ���������� � ������� �� �������� (�������������
��������). � ������ ������ ������ ����������� ��������� �������:
4 ������ ������� 5 2 1 1
������ ������ �������� ����� ������ (������ ��� ����� �� ��������� 0-18).
������ ���� � ��� ��� ������, � ������ � ��� �������. ������ ��� ������� ��
������ �����. ��������� ���� ����������, ������� ��� ����� �������� ���, ��
������� ������� ���������� ���������� ������� ������, �������� � �����������
��������. ���� ����� ��������� ���������� ����� ��� ����� ����, �������������,
��� ������ � ���� �� ������ ����� ���� ��������� �����. ��������
���������, ������� ��������� ��������������� ������ � ������� ��������.
��������� ������ �������� �� ������, � ������� ������������ ������� � ���,
���������� ��������� �����, �������� � ����������� ��������, � ����� �������
��������� (��� �������� ����������� �����). � �������� ������� �������
������ ������������ ����� ������. ��������� ������ ��������� ������ ��
����� �����, � ����������� �������� ���������� �� ������� ������.
��� ���������� �������� �������� ������. ��������, ������ ��� ������ ����
� ���������� ������ �� ������������� ��� �� ������, ��� ��� �� ����� ���������,
���������� �� ���� ������� �����, ������ �� ��������� �������� ����������
��������. �� ��� ��������� ������ ������ ������ � ������������ �����
������, ��� ������� ����, �� �������� � �������������� ������.
���������� ������ ��������������� ������������� ����������� ���������
������, ������ ������ �� ����� �� ��������� ���������� � ����� �� ����������
� ����������� ��������������� ���������. ����� ����, ��� ��������� ��������
������ �����, ��� ������ ��������� ������� ������� ���������� ���
������� ������ � ��������� ��� � ��������������� ����� ���������. �������
������� ���������� ����������� ����� ������� ������������ ����� ������, �����������
�������, �� ���������� ������� �� ������� �������; ����������
������ ���� � ��������� �������. ����� ��������� ������ ���������� �������������
������ �� ������� ������ ������ �� �������, � ������� ����������
��������� �������������� ������ �� ���� �������. */
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
