#ifndef __SUBSET_H
#define __SUBSET_H

typedef struct Node Node;
typedef struct Node *PtrToNode;

struct Node
{
    int value;
    PtrToNode NextPtr;
};

typedef struct HashTable
{
    PtrToNode NextPtr;

} HashTable;

typedef HashTable* Table;

int HashCode(int key);
void Insert(Table Array, int val);
void initArray(Table Array);
void rehash();

#endif