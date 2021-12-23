#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dequeue.h"

int main()
{
    Queue Q = EmptyQueue();

    char c[7];
    ElementType Real;
    ElementType Complex;

    char c1[] = "push";
    char c2[] = "pop";
    char c3[] = "inject";
    char c4[] = "eject";
    char c5[] = "exit";

    printf("Enter the operation(s) you want to perform: \n");
    printf("Push: To enter an element at the start of the queue.\n");
    printf("Pop: To delete the first element of the queue.\n");
    printf("Inject: To enter an element at the end of the queue.\n");
    printf("Eject: To delete the last element of the queue.\n");
    printf("Exit: To exit the program.\n");

    while (scanf("%s", c) != EOF)
    {
        if (strcasecmp(c, c5) == 0)
        {
            break;
        }
        else if (strcasecmp(c, c1) == 0)
        {
            scanf("%lf %lf", &Real, &Complex);
            Push(Q, Real, Complex);
            printQueue(Q);
            printf("\n");
        }
        else if (strcasecmp(c, c2) == 0)
        {
            Pop(Q);
            printQueue(Q);
            printf("\n");
        }
        else if (strcasecmp(c, c3) == 0)
        {
            scanf("%lf %lf", &Real, &Complex);
            Inject(&Rear, Real, Complex);
            printQueue(Q);
            printf("\n");
        }
        else if (strcasecmp(c, c4) == 0)
        {
            Eject(&Rear);
            printQueue(Q);
            printf("\n");
        }
        else
        {
            printf("invalid operation.\n");
        }
    }

    deleteQueue(Q);

    return 0;
}