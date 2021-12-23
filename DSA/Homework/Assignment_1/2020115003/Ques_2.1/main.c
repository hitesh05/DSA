#include "Singly_Linked_List.h"
#include "IntElement.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main()
{
    ElementType n;

    //Creating the header node:
    List head = CreateEmptyList();

    //Number to be found:
    ElementType number_find = 0;
    int index;

    //inputting elements in the linked list:
    printf("Enter elements of the linked list (0 to end): \n");
    printf("The insertion will be at the front of the list: \n");
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;

        List *LP = &head;
        InsertAtFront(LP, n);
    }

    printf("Do You want to insert any elements at the rear of the list? (1/0)\n");

    int test2;
    scanf("%d", &test2);

    if (test2 == 1)
    {
        printf("Enter numbers to insert at rear (0 to end): \n");

        while (scanf("%d", &n) != EOF)
        {
            if (n == 0)
                break;

            InsertAtRear(head, n);
        }
    }

    //initialising indices:
    enterIndex(head); //last element entered by the user will be at index = 0

    //printing initial list:
    printf("Initial linked list: \n");
    printList(head);
    printf("\n");

    //Finding the Element:
    printf("Enter element to find: \n");
    scanf("%d", &number_find);

    index = FindLast(head, number_find);
    printf("%d is at Index = %d\n\n", number_find, index);

    //Deleting an element:
    printf("Do you want to delete any element? (1/0)\n");

    int test;
    ElementType elemnent_del;

    scanf("%d", &test);

    if (test == 1)
    {
        printf("Enter number to delete: \n");
        scanf("%d", &elemnent_del);
        FindDelete(head, elemnent_del);
    }

    printf("Linked List after deletion: \n");
    printList(head);

    //Finding the Element in modified linked list:
    printf("Enter element to find: \n");
    scanf("%d", &number_find);

    index = FindLast(head, number_find);
    printf("%d is at Index = %d\n\n", number_find, index);

    emptyList(head);

    return 0;
}