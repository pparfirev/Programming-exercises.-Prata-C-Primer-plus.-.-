/* Предположим, что в файле list.h (листинг 17.3) используется следующее определение
списка:
#define MAXSIZE 100
typedef struct list
{
    Item entries[MAXSIZE]; // массив элементов
    int items; // количество элементов в списке
) List;
Перепишите функции в файле list.с (листинг 17.5), чтобы они соответствовали
этому определению, и протестируйте результирующий код с помощью программы
films3.с (листинг 17.4). */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* local function prototype */
static void CopyToNode(Item item, Node * pnode);

/* interface functions   */
/* set the list to empty */
void InitializeList(List * plist)
{
    //plist.entries[0] = NULL;
    plist->items = 0;
}

/* returns true if list is empty */
bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

/* returns true if list is full */
bool ListIsFull(const List * plist)
{
    if (plist->items == MAXSIZE)
        return true;
    else
        return false;
}

/* returns number of nodes */
unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}

/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation)  */
bool AddItem(Item item, List * plist)
{
    if (plist->items == MAXSIZE)
        return false;
    else
    {
        plist->entries[plist->items++] = item;
        return true;
    }
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List * plist, void (* pfun)(Item item))
{
    int i;
    for (i = 0; i < plist->items; i++)
        (*pfun)(plist->entries[i]); /* apply function to item in list */
}

/* free memory allocated by malloc() */
/* set list pointer to NULL          */
void EmptyTheList(List * plist)
{
    plist->items = 0;
}

/* local function definition  */
/* copies an item into a node */
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;  /* structure copy */
}
