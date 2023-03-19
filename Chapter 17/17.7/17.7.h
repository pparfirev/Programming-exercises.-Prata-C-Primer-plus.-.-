#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
#define SLEN 81

typedef struct item
{
    char wrd[SLEN];
    int count;
} Item;

#define MAXITEMS 100

typedef struct node
{
    Item item;
    struct node *left; // pointer to right branch
    struct node *right; // pointer to left branch
} Node;

typedef struct tree
{
    Node *root; // pointer to root of tree
    int size; // number of items in tree
} Tree;

// Function prototypes
// Operation:      initialize a tree to empty
// Preconditions:  ptree points to a tree
// Postconditions: the tree is initialized to empty
void InitializeTree(Tree *ptree);

// Operation:      determine if tree is empty
// Preconditions:  ptree points to a tree
// Postconditions: function returns true if tree is
//                 empty and returns false otherwise
bool TreeIsEmpty(const Tree *ptree);

// Operation:      determine if tree is full
// Preconditions:  ptree points to a tree
// Postconditions: function returns true if tree is
//                 full and returns false otherwise
bool TreeIsFull(const Tree *ptree);

// Operation:      determine number of items in tree
// Preconditions:  ptree points to a tree
// Postconditions: function returns number of items in tree
int TreeItemCount(const Tree *ptree);

// Operation:      add an item to a tree
// Preconditions:  pi is address of item to be added
//                 ptree points to an initialized tree
// Postconditions: if possible, function adds item to tree
//                 and returns true; otherwise,
//                 the function returns false
bool AddItem(const Item *pi, Tree *ptree);

// Operation:      find an item in a tree
// Preconditions:  pi points to an item
//                 ptree points true if item is in
// Postconditions: function returns true if item is in
//                 tree and returns false otherwise
bool InTree(const Item *pi, const Tree *ptree);

// Operation:      delete an item from a tree
// Preconditions:  pi is address of item to be deleted
//                 ptree points to an initialized tree
// Postconditions: if possible, function deletes item
//                 from tree and returns true;
//                 otherwise, the function returns false;
bool DeleteItem(const Item *pi, Tree *ptree);

// Operation:      apply a function to each item in
//                 the tree
// Preconditions:  ptree points to a tree
//                 pfun points to a function that takes
//                 an Item argument and has no return
//                 value
// Postconditions: the function pointed to by pfun is
//                 executed once for each item in tree
void Traverse(const Tree *ptree, void(*pfun)(Item item));

// Operation:      return address of item in a tree
// Preconditions:  pi points to an item
//                 ptree to an initialized tree
// Postconditions: function returns address if item is
//                 in tree and returns NULL otherwise
const Item *WhereInTree(const Item *pi, const Tree *ptree);
#endif // _TREE_H_
