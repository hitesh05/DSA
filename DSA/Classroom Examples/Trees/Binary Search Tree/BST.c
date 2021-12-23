#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

SearchTree Insert(SearchTree T, ElementType X)
{
    if (T == NULL)
        T = MakeNode(X);

    else if (X < T->Element)
        T->Left = Insert(T->Left, X);
    else
        T->Right = Insert(T->Right, X);

    return T;
}

Position Find(SearchTree T, ElementType X)
{
    if (T == NULL)
    {
        return T;
    }
    else if (X == T->Element)
    {
        return T;
    }
    else if (X < T->Element)
    {
        return Find(T->Left, X);
    }
    else
    {
        return Find(T->Right, X);
    }
}

Position minValue(Position Node)
{
    while (Node && Node->Left != NULL)
        Node = Node->Left;

    return Node;
}

Position Delete(SearchTree T, ElementType X)
{
    //assuming the element to be deleted exists.

    Position TempNode;

    if (X < T->Element)
        T->Left = Delete(T->Left, X);
    else if (X > T->Element)
        T->Right = Delete(T->Right, X);

    else //now we have found the node to be deleted. 3 cases possible.
    {
        //one of the children is null
        if (T->Left == NULL || T->Right == NULL)
        {
            TempNode = T;
            if (T->Right == NULL)
            {
                T = T->Left;
                free(TempNode);
                return T;
            }
            else
            {
                T = T->Right;
                free(TempNode);
                return T;
            }
        }
        else //node has 2 sub trees
        {
            //we will copy the smallest element of the right subtree to the node that
            //has to be deleted and free the memory of that smallest element.

            TempNode = minValue(T->Right);

            T->Element = TempNode->Element;
            T->Right = Delete(T->Right, TempNode->Element);
        }
    }

    return T;
}