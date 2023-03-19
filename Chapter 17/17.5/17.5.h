#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>
typedef char Item;

#define MAXSTACK 100

typedef struct stack
{
    Item items[MAXSTACK]; // holds info
    int top; // index of first empty slot
} Stack;

// Operation:     initialize the stack
// Precondition:  ps points to a stack
// Postcindition: stack is initialized to being empty
void InitializeStack(Stack *ps);

// Operation:     check if stack is full
// Precondition:  ps points to previously initialized stack
// Postcondition: returns True if stack if full, else False
bool FullStack(const Stack *ps);

// Operation:     check if stack is empty
// Precondition:  ps points to previously initialized stack
// Postcondition: returns True if stack is empty, else False
bool EmptyStack(const Stack *ps);

// Operation:     push item onto top of stack
// Precondition:  ps points to previously initialized stack
//                item is to be placed on top of stack
// Postcondition: if stack is not empty, item is placed at
//                top of stack and function returns
//                True; otherwise, stack is unchanged and
//                function returns False
bool Push(Item item, Stack *ps);

// Operation:     remove item top of stack
// Precondition:  ps points to previously initialized stack
// Postcondition: if stack is not empty, item at top of
//                stack is copied to *pitem and deleted from
//                operation empties the stack, the stack is
//                reset to empty. If the unchanged and the
//                function returns False
bool Pop(Item *pitem, Stack *ps);
#endif // STACK_H_
