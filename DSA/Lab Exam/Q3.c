#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *Next;
};
typedef struct Node Stk;
typedef struct Node *Stack;

Stack initStack()
{
    Stack S = (Stack)malloc(sizeof(Stk));
    assert(S != NULL);

    S->Next = NULL;

    return S;
}

void pop(Stack S)
{
    if (S->Next == NULL)
        return;

    Stack header_node, delete_node;
    header_node = S;
    delete_node = S->Next;

    header_node->Next = delete_node->Next;
    free(delete_node);
}

void push(Stack S, int n)
{
    Stack Temp = initStack();
    Temp->data = n;

    if (S->Next == NULL)
    {
        S->Next = Temp;
    }
    else
    {
        Temp->Next = S->Next;
        S->Next = Temp;
    }
}

int main()
{
}