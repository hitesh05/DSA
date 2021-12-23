#ifndef __SLL_H
#define __SLL_H

#include "IntElement.h"

typedef struct Node ListNode;
typedef struct Node *PtrToNode;

typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    ElementType Element;
    struct Node *Next;
};

PtrToNode MakeNode(ElementType X);

List CreateEmptyList(); //contains the dummy node

void InsertAtFront(List *LP, ElementType X); //we are passing the address to the list pointer

#endif