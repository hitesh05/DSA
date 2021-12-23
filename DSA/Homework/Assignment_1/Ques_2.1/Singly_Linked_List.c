#include "Singly_Linked_List.h"
#include "IntElement.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

PtrToNode MakeNode(ElementType X)
{
    PtrToNode P = (PtrToNode)malloc(sizeof(ListNode));
    assert(P != NULL);

    P->Element = X;
    // P->index = index;   //we do this in a separate function
    P->Next = NULL;

    return P;
}

List CreateEmptyList()
{
    PtrToNode P = MakeNode(0);
    return P;
}

void enterIndex(List L)
{
    int Index = -1;

    for (List i = L; i != NULL; i = i->Next)
    {
        i->index = Index;
        Index++;
    }
}

void InsertAtFront(List *LP, ElementType X)
{
    PtrToNode PNew = MakeNode(X);
    List L = *LP; //now we have access to the list

    if (L->Next == NULL)
    {
        L->Next = PNew;
    }
    else
    {
        PNew->Next = L->Next;
        L->Next = PNew;
    }
}

void InsertAtRear(List L, ElementType X)
{
    PtrToNode PNew = MakeNode(X);

    while (L->Next != NULL)
    {
        L = L->Next;
    }

    L->Next = PNew;
}

int FindLast(List L, ElementType X) //header node and the element to be found are passed as parameters
{
    int Index, flag = 0;

    while (L->Next != NULL)
    {
        if (L->Element == X)
        {
            Index = L->index;
            L = L->Next;
            flag = 1;
        }
        else
            L = L->Next;
    }
    if (L->Next == NULL)
    {
        if (L->Element == X)
        {
            Index = L->index;
            flag = 1;
        }
    }

    if (flag == 0)
    {
        return -1;
    }
    else
    {
        return Index;
    }
}

void DeleteAll(List curr_node, List delete_node, int Index) //index of curr_node is passed
{
    curr_node->Next = delete_node->Next;
    free(delete_node);

    for (List i = curr_node; i != NULL; i = i->Next) //updating the indices
    {
        i->index = Index;
        Index++;
    }
}

void FindDelete(List L, ElementType X) //header node and element to be deleted are passed
{
    int index;
    List curr_node, delete_node;

    while (L->Next != NULL)
    {
        if (L->Next->Element == X)
        {
            index = L->index;
            curr_node = L;
            delete_node = L->Next;
            DeleteAll(curr_node, delete_node, index); //index is of curr_node
        }
        else
            L = L->Next;
    }
}

void emptyList(List L)
{
    List delete_node, header_node;

    while (L->Next != NULL)
    {
        header_node = L;
        delete_node = L->Next;

        header_node->Next = delete_node->Next;
        free(delete_node);
    }
    free(L); //deleting the header node also.
}

void printList(List head)
{
    if (head == NULL)
    {
        printf("The list does not exist.\n");
        return;
    }

    for (Position cnode = head; cnode != NULL; cnode = cnode->Next)
    {
        if (cnode == head) //we dont print the contents of the header node
        {
            continue;
        }
        else
        {
            printf("%d\n", cnode->Element);
        }
    }
}
