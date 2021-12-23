#ifndef __MYSTACK_H
#define __MYSTACK_H

typedef double ElementType;

typedef struct Node Stk;
typedef struct Node *Stack;

struct Node
{
    ElementType real;
    ElementType complex;
    Stack Next;
};

Stack InitStack();

void Push(Stack S, ElementType real, ElementType complex);
void Pop(Stack S);
void printStack(Stack S);

void deleteStack(Stack head);

#endif