#ifndef __QUEUE_H
#define __QUEUE_H

typedef double ElementType;

typedef struct Node Que;
typedef struct Node *Queue;

Queue Rear;
Queue Front;

struct Node
{
    ElementType real;
    ElementType complex;
    Queue Next;
    Queue Prev;
};

Queue InitQueue();
Queue EmptyQueue();

void printQueue(Queue Q);
void Push(Queue Q, ElementType Real, ElementType Complex);
void Pop(Queue Q);
void Inject(Queue *Rear, ElementType Real, ElementType Complex);
void Eject(Queue *Q);

void deleteQueue(Queue head);

#endif