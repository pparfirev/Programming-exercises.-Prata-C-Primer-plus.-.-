/* Переделайте программу, описанную в упражнении 2, чтобы в ней использовались
только автоматические переменные. Обеспечьте в программе тот же самый
пользовательский интерфейс, т.е. она должна предлагать пользователю ввести
режим и т.д. Однако у вас будет другой набор вызовов функций. */

#include <stdio.h>
#include <stdlib.h>

int set_mode(int m);
float get_dist(int mode_w);
float get_val(int mode_w);
void show_info(int mode_w, float dist, float val);
int main(void)
{
    int mode;
    int prev_mode = 0;
    int mode_count;
    printf("Enter 0 for metric system or 1 for imperial system: ");
    scanf("%d", &mode);
    while(mode >= 0)
    {
        if(mode != 1 && mode != 0)
        {
           mode = prev_mode;
           if(mode == 0)
                printf("Using wrong setup. Using setup %d (metric)\n", mode);
            else if(mode == 1)
                printf("Using wrong setup. Using setup %d (american)\n", mode);
        }
        set_mode(mode);
        prev_mode = mode;
        float distance = get_dist(mode);
        float value = get_val(mode);
       // printf("%f, %f\n", distance, value);
        show_info(mode, distance, value);
        printf("Enter 0 for metric system or 1 for imperial system (-1 for exit): ");
        scanf("%d", &mode);
        mode_count++;
    }
    return 0;
}
int set_mode(int m)
{
    int mode_w;
    if(m == 0)
        mode_w = m;
    else if(m == 1)
        mode_w = m;
    else
    {
    if(mode_w == 0)
        printf("Using wrong setup. Using setup %d (metric)\n", mode_w);
    else if(mode_w == 1)
        printf("Using wrong setup. Using setup %d (american)\n", mode_w);
    }
    return mode_w;
}
float get_dist(int mode_w)
{
    float dist;
    if(mode_w == 0)
        printf("Enter distance in kilometres: ");
    if(mode_w == 1)
        printf("Enter distance in miles: ");
    scanf("%f", &dist);
    return(dist);


}
float get_val(int mode_w)
{
    float val;
     if(mode_w == 0)
        printf("Enter the value of spent gasoline in litres: ");
    if(mode_w == 1)
        printf("Enter the value of spent gasoline in gallons: ");
    scanf("%f", &val);
    return val;
}
void show_info(int mode_w, float dist, float val)
{
    if(mode_w == 0)
        printf("Fuel consomption is %.2f liter per kilometer.\n", (val * 100 / dist));
    if(mode_w == 1)
        printf("Fuel consomption is %.1f gallons per mile.\n", (dist / val));
}
