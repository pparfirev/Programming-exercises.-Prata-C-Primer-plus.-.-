/* Напишите программу, которая соответствуем следующим требованиям.
    а. Программа внешне определяет шаблон сруктуры name с двумя членами: строкой
для хранения имени и строкой для хранения фамилии.
    б. Программа внешне определяет шаблон структуры student с тремя членами:
сфуктурой name, массивом grade для хранения трех оценок в виде чисел с плаваю-
щей запятой и переменной для хранения среднего значения этих трех оценок.
    в. Программа содержит функцию main(), где объявляется массив из CSIZE
(с CSIZE = 4) структур student, в которых инициализируются члены name
именами по вашему выбору. Для выполнения задач, описанных в частях г), д),
е) и ж), используйте функции.
    г. Программа интерактивно вводит оценки для каждого студента, запрашивая
у пользователя ввод имени студента и его оценок. Поместите оценки в массив
grade соответствующей структуры. Требуемый цикл можно реализовать в
main() или в специальной функции по вашему усмотрению.
    д. Программа вычисляет среднюю оценку для каждой структуры и присваивает
ее соответствующему члену.
    е. Программа выводит информацию из каждой структуры.
    ж. Программа выводит среднее значение по курсу для каждого числового члена
структуры. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 25
#define CSIZE 4
#define MAXS 100
struct name
{
    char mname[LEN];
    char sname[LEN];
};
struct student
{
    struct name fname;
    float grade[3];
    float mid;
};
char *s_gets(char *st, int n);
void EntGrade(struct student *list, int n);
void OutData(struct student *list, int n);
void MidGrade(struct student *list);
int main()
{
    char mnameTmp[LEN];
    char snameTmp[LEN];
    struct student list[CSIZE] =
    {
        {{"Name", "Surname"}},
        {{"Michael", "Fox"}},
        {{"Jamie", "Fox"}},
        {{"Samuel", "Jackson"}},
    };
    int count = 0;
    printf("Enter the name of student: \n");
    printf("Or enter the empty string to stop entering.\n");
    while(count < CSIZE && s_gets(mnameTmp, LEN) != NULL && mnameTmp[0] != '\0')
    {
        for(int n = 0; n < CSIZE; n++)
        {
            if(!strcmp(mnameTmp, (list + n)->fname.mname))
            {
                puts("Now, enter the surname: ");
                s_gets(snameTmp, LEN);
                if(!strcmp(snameTmp, (list + n)->fname.sname))
                   {
                       EntGrade(list, n);
                       //continue;
                   }
                else
                {
                    puts("Can't find entered surname: ");
                    continue;
                }
            }
            else
                continue;
        }
        count++;
        puts("Enter Another name of student: ");
    }
    if(count > 0)
    {
        puts("Here's info about students: ");
        for(int index = 0; index < CSIZE; index++)
            OutData(list, index);
        MidGrade(list);
    }
    else
        puts("Data is empty");
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n'); // NewLine searching
        if(find) // If adress doesn't NULL
            *find = '\0'; // Place ZeroSymbol
        else
            while(getchar() != '\n')
            continue; // Drop the end of the line
    }
    return ret_val;
}
void EntGrade(struct student *list, int n)
{
    puts("Enter 3 grades of student: ");
    scanf("%f%f%f", &(list + n)->grade[0], &(list + n)->grade[1],
          &(list + n)->grade[2]);
    (list + n)->mid = (((list + n)->grade[0] + (list + n)->grade[1] +
                        (list + n)->grade[2]) / 3);
    while(getchar() != '\n')
            continue; // Clean input string
    //printf("%f %f %f %f", (list + n)->grade[0], (list + n)->grade[1],
    //      (list + n)->grade[2], (list + n)->mid);
}
void OutData(struct student *list, int n)
{
    printf("%s %s, ", (list + n)->fname.mname, (list + n)->fname.sname);
    printf("Grades: %.2f, %.2f, %.2f. ", (list + n)->grade[0], (list + n)->grade[1],
          (list + n)->grade[2]);
    printf("Middle Grade: %.2f\n", (list + n)->mid);
}
void MidGrade(struct student *list)
{
    float midgrade1 = 0;
    float midgrade2 = 0;
    float midgrade3 = 0;
    for(int n = 0; n < CSIZE; n++)
    {
        midgrade1 += (list + n)->grade[0];
        midgrade2 += (list + n)->grade[1];
        midgrade3 += (list + n)->grade[3];

    }
    printf("Middle grades of subjects: %f, %f, %f\n", (midgrade1 / CSIZE),
           (midgrade2 / CSIZE), (midgrade3 / CSIZE));
}
