#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myStack.h"

int main(void)
{
    Stack S = InitStack(); //header node
    char c[5];
    ElementType Real;
    ElementType Complex;

    char c1[] = "push";
    char c2[] = "pop";
    char c3[] = "exit";

    printf("Enter the operation(s) you want to perform: \n");
    printf("Push: To eneter an element at the start of the queue.\n");
    printf("Pop: To delete the first element of the queue.\n");
    printf("Exit: To exit the program.\n");
    
    while (scanf("%s", c) != EOF)
    {
        if (strcasecmp(c, c3) == 0)
        {
            break;
        }
        else if (strcasecmp(c, c1) == 0)
        {
            scanf("%lf %lf", &Real, &Complex);
            Push(S, Real, Complex);
            printStack(S);
            printf("\n");
        }
        else if (strcasecmp(c, c2) == 0)
        {
            Pop(S);
            printStack(S);
            printf("\n");
        }
        else
        {
            printf("invalid operation.\n");
        }
    }

    return 0;
}