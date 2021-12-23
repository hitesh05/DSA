#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dequeue.h"

Queue EmptyQueue()
{
    Queue Q = (Queue)malloc(sizeof(Que));
    assert(Q != NULL);

    Q->Next = NULL;
    // Q->Prev = NULL;
    Rear = Q;

    return Q;
}

Queue InitQueue()
{
    Queue Q = (Queue)malloc(sizeof(Que));
    assert(Q != NULL);

    Q->Next = NULL;

    return Q;
}

void Push(Queue Q, ElementType Real, ElementType Complex) //insert at front, same as in stack
{
    Queue Temp = InitQueue();

    if (Q->Next == NULL)
    {
        Temp->real = Real;
        Temp->complex = Complex;
        Temp->Prev = Q;
        Q->Next = Temp;
        Rear = Temp;
    }
    else
    {
        Temp->real = Real;
        Temp->complex = Complex;
        Temp->Next = Q->Next;
        Temp->Prev = Q;
        Temp->Next->Prev = Temp;
        Q->Next = Temp;
    }
}

void Pop(Queue Q)
{
    Queue header_node, delete_node, next_node;

    if (Q->Next == NULL)
    {
        printf("The dequeue is empty.\n");
        return;
    }
    else
    {
        header_node = Q;
        delete_node = Q->Next;
        next_node = delete_node->Next;

        if (Q->Next->Next == NULL)
        {
            Rear = header_node;
        }

        header_node->Next = next_node;
        if (header_node->Next != NULL)
        {
            next_node->Prev = header_node;
        }
        free(delete_node);
    }
}

void Inject(Queue *Rear, ElementType Real, ElementType Complex)
{
    Queue Temp = InitQueue();
    Queue curr_node = *Rear;

    Temp->real = Real;
    Temp->complex = Complex;
    Temp->Prev = curr_node;

    *Rear = Temp;
    curr_node->Next = Temp;

    // Rear = Temp;
}

void Eject(Queue *Rear)
{
    Queue prev_node, delete_node;
    delete_node = *Rear;

    if (delete_node->Prev == NULL)
    {
        printf("The queue is empty.\n");
        return;
    }

    prev_node = delete_node->Prev;
    prev_node->Next = NULL;

    free(delete_node);
    *Rear = prev_node;
}

void printQueue(Queue Q) //Q is the header node
{
    if (Q->Next != NULL)
    {
        for (Queue cnode = Q; cnode != NULL; cnode = cnode->Next)
        {
            if (cnode == Q)
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
