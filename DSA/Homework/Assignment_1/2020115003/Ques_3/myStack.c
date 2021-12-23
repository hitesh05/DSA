#include "myStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

Stack InitStack() //allocating memory
{
    Stack S = (Stack)malloc(sizeof(Stk));
    assert(S != NULL);

    S->Next = NULL;

    return S;
}

void Push(Stack S, ElementType Real, ElementType Complex) //S is the header node
{
    Stack Temp = InitStack();

    if (S->Next == NULL) //if Temp is the first element in the stack
    {
        Temp->real = Real;
        Temp->complex = Complex;
        S->Next = Temp;
    }
    else
    {
        Temp->real = Real;
        Temp->complex = Complex;
        Temp->Next = S->Next;
        S->Next = Temp;
    }
}

void Pop(Stack S) //S is the header node
{
    Stack header_node, delete_node;
    header_node = S; //storing the header node and the delete node(i.e. the last element of the stack (to pop it))
    delete_node = S->Next;

    if (S->Next == NULL)
    {
        printf("The stack is empty.\n");
        return;
    }
    else
    {
        header_node->Next = delete_node->Next;
        free(delete_node);
    }
}

void printStack(Stack S) //S is the header node
{
    if (S->Next != NULL)
    {
        for (Stack cnode = S; cnode != NULL; cnode = cnode->Next)
        {
            if (cnode == S)
            {
                continue;
            }
            else
            {
                printf(" {%.2lf,%.2lf} ", cnode->real, cnode->complex);
            }
        }
    }
}
