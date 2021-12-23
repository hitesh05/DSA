#include "Singly_Linked_List.h"
#include <malloc.h>
#include <assert.h>

PtrToNode MakeNode(ElementType X)
{
    PtrToNode P = (PtrToNode)malloc(sizeof(ListNode));
    assert(P != NULL);

    P->Element = X;
    P->Next = NULL;

    return P;
}

List CreateEmptyList()
{
    PtrToNode P = MakeNode(0);
    return P;
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

void printList(List head)
{
    for (Position cnode = head; cnode != NULL; cnode = cnode->Next)
    {
        if (cnode == head)
        {
            continue;
        }
        else
        {
            printf("%d\n", cnode->Element);
        }
    }
}
 
int main()    //we can also make a separate file named main.c
{
    ElementType rollno;
    PtrToNode cnode;

    List head = CreateEmptyList();

    while (scanf("%d", &rollno) != EOF)
    {
        List *LP = &head;
        InsertAtFront(LP, rollno);
    }

    printf("List of roll nos:\n");
    printList(head);

    return 0;
}