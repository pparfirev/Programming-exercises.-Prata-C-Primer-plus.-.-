/* В полярной системе координат вектор описывается модулем и углом с осью х в
направлении против часовой стрелки. В прямоугольной системе координат тот
же вектор описывается составляющими х и у. Напишите программу,
которая считывает значения модуля и угла (в градусах) вектора, а затем отображает
составляющие х и у. Воспользуйтесь следующими уравнениями:
х = r cos А; у = r sin А
Для выполнения преобразования применяйте функцию, которая принимает
структуру, содержащую полярные координаты, и возвращает структуру, содержащую
прямоугольные координаты (или, если хотите, выберите вариант с указателями
на эти структуры). */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct polar
{
    double rad;
    double angle;
};
struct decart
{
    double x;
    double y;
};
struct decart pol_to_dec(const struct polar *);
int main()
{
    struct polar ent;
    struct decart ans;
    double module, fi;
    printf("Enter module and angle of vector, or press q to exit: ");
    while(scanf("%lf%lf", &ent.angle, &ent.rad) == 2)
    {
        ans = pol_to_dec(&ent);
        printf("Decart coordinates is: x = %0.2lf, y = %0.2lf\n", ans.x, ans.y);
        printf("Enter module and angle of vector, or press q to exit: ");
    }
    puts("Program Closed.");
    return 0;
}
struct decart pol_to_dec(const struct polar *st)
{
    struct decart result;
    double grad_ang = (3.141 / 180.0) * st->angle;
    result.x = st->rad * cos(grad_ang);
    result.y = st->rad * sin(grad_ang);
    return result;
};
