#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int root, elements, length;
    SearchTree T = NULL; //address to the root of the tree.
    srand(time(NULL));

    // printf("Enter the elements of the tree.\n");
    // while (scanf("%d", &elements) != EOF)
    // {
    //     T = Insert(T, elements);
    // }

    T = Insert(T, 10);
    T = Insert(T, 8);
    T = Insert(T, 9);
    T = Insert(T, 6);
    T = Insert(T, 7);
    T = Insert(T, 20);
    T = Insert(T, 25);
    T = Insert(T, 28);
    T = Insert(T, 33);
    T = Insert(T, 23);
    printf("Enter the elements of the tree.\n");

    printf("Elements of tree in sorted order: \n");
    bstsort(T);

    printf("\nEnter the element whose node you want the depth of: \n");
    int X;
    scanf("%d", &X);
    Position P = Find(T, X);
    finddepth(T, P);

    height(T);

    isbst(T);

    inRange(T, 10, 23);
    printf("\n");

    avgDepth();

    return 0;
}