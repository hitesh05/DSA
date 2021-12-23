#ifndef __SLL_H
#define __SLL_H

#include "IntElement.h"

typedef struct Node ListNode;
typedef struct Node *PtrToNode;

typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    ElementType Element;
    int index;
    struct Node *Next;
};

PtrToNode MakeNode(ElementType X);
List CreateEmptyList();                                      //contains the dummy node
void InsertAtFront(List *LP, ElementType X);                 //we are passing the address to the list pointer
void printList(List head);                                   //printing the linked list
int FindLast(List L, ElementType X);                         //finding an element(max index will be printed in case of multiple entries)
void FindDelete(List L, ElementType X);                      //locating the element that has to be deleted
void DeleteAll(List curr_node, List delete_node, int Index); //deleting the element
void enterIndex(List L);                                     //initialising all indices (last enetered elemnt will have index = 0)
void InsertAtRear(List L, ElementType X);                    //inserting at the end of the list
void emptyList(List L);                                      //deleting the whole list, including the header.
#endif