static int mode_w = 0;
static float dist;
static float value;

void set_mode(m)
{
    char setup[20];
    if(m == 0)
        mode_w = m;
    else if(m == 1)
        mode_w = m;
    else
    {
    if(mode_w == 0)
        printf("Using wrong setup. Using setup %d (metric)\n", mode_w);
    else
        printf("Using wrong setup. Using setup %d (american)\n", mode_w);
    }
}
void get_info()
{
    if(mode_w == 0)
        printf("Enter distance in kilometres: ");
    if(mode_w == 1)
        printf("Enter distance in miles: ");
    scanf("%f", &dist);
    if(mode_w == 0)
        printf("Enter the value of spent gasoline in litres: ");
    if(mode_w == 1)
        printf("Enter the value of spent gasoline in gallons: ");
    scanf("%f", &value);

}
void show_info()
{
    if(mode_w == 0)
        printf("Fuel consomption is %.2f liter per kilometer.\n", (value * 100 / dist));
    if(mode_w == 1)
        printf("Fuel consomption is %.1f gallons per mile.\n", (dist / value));
}

