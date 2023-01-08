/* Напишите программу с таким же поведением, как в упражнении 6, но используйте
для хранения информации о шрифте переменную типа unsigned long, а
для манипулирования этой информацией - побитовые операции вместо членов
струкуры с битовыми полями. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ID_MASK    0xFF
#define SIZE_MASK  0x7F
#define LEFT       0x00000
#define RIGHT      0x10000
#define CENTER     0x08000
#define ALIGN_MASK 0x18000
#define REFULAR    0x00000
#define BOLD       0x20000
#define ITALIC     0x40000
#define UNDERLINE  0x80000
#define STYLE_MASK 0xE0000
#define SIZE_SHIFT 8

typedef unsigned long font;

char do_menu(font *f);
char get_choice(const char *);
void show_menu(void);
void show_font(font f);
void eatline(void);
void get_id(font *f);
void get_size(font *f);
void get_align(font *f);

int main()
{
    font sample = 1 | (12 <<SIZE_SHIFT) | LEFT | ITALIC;
    while(do_menu(&sample) != 'q')
        continue;
    puts("Program Closed.");
    return 0;
}
char do_menu(font *f)
{
    char responce;
    show_font(*f);
    show_menu();
    responce = get_choice("abcdefq");
    switch(responce)
    {
        case 'a': get_id(f); break;
        case 'b': get_size(f); break;
        case 'c': get_align(f); break;
        case 'd': *f ^= BOLD; break;
        case 'e': *f ^= ITALIC; break;
        case 'f': *f ^= UNDERLINE; break;
        case 'q': break;
        default: printf("Wrong menu litera.\n");
    }
    return responce;
}
char get_choice(const char *str)
{
    char ch;
    ch = getchar();
    ch = tolower(ch);
    eatline();
    while(strchr(str, ch) == NULL)
    {
        printf("Enter one of the following: %s\n", str);
        ch = tolower(getchar());
        eatline();
    }
    return ch;
}
void eatline(void)
{
    while(getchar() != '\n')
        continue;
}
void show_menu(void)
{
    puts("a. Change font   b. Change Size    c. Change Alignment");
    puts("d. Bold          e. Italic         f. Underline");
    puts("q. Quit");
}
void show_font(font f)
{
    printf("\n%4s %4s %9s %3s %3s %3s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%4lu %4lu", f & ID_MASK, (f & SIZE_MASK) >> SIZE_SHIFT);
    switch(f & ALIGN_MASK)
    {
        case LEFT   : printf("%7s", "left"); break;
        case RIGHT  : printf("%7s", "right"); break;
        case CENTER : printf("%7s", "center"); break;
        default     : printf("%7s", "unknown"); break;
    }
    printf("%8s %3s %3s\n", (f & BOLD) == BOLD ? "ON" : "OFF",
                            (f & ITALIC) == ITALIC ? "ON" : "OFF",
                            (f & UNDERLINE) == UNDERLINE ? "ON" : "OFF");
}
void get_id(font *f)
{
    int id;
    printf("Enter font ID from 0 to 255: ");
    scanf("%d", &id);
    id = id & ID_MASK;
    *f |= id;
    eatline();
}
void get_size(font *f)
{
    int size;
    printf("Enter font size from 0 to 127: ");
    scanf("%d", &size);
    *f |= (size << SIZE_SHIFT) & SIZE_MASK;
    eatline();
}
void get_align(font *f)
{
    puts("Select alignment: ");
    puts("l. Left    c. Center    r. Right");
    switch(get_choice("lcr"))
    {
        case 'l': *f &= ~ALIGN_MASK; *f |= LEFT; break;
        case 'c': *f &= ~ALIGN_MASK; *f |= CENTER; break;
        case 'r': *f &= ~ALIGN_MASK; *f |= RIGHT; break;
        default: printf("Alignment Problem.\n");
    }
}
