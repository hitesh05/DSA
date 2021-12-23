#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

//Question 2 Horner's rule separate chaining:
unsigned int Horner(int string[], int n, int x, int table_size)
{
    unsigned long long int result = string[0];
    for (int i = 1; i < n; i++)
        result = result * x + string[i];

    return result % table_size;
}

void initArray_SC_2(Array_SC_2 Array, int table_size)
{
    for (int i = 0; i < table_size; i++)
    {
        Array[i].head = NULL;
        Array[i].tail = NULL;
    }
}

int Insert_SC_2(Array_SC_2 Array, int val, int num_elems, int table_size, char word[])
{
    Array_SC_2 List = &Array[val];
    int collisions = 0;

    PtrToNode_2 Temp = (PtrToNode_2)malloc(sizeof(Node_2));

    //Temp->value = val;
    strcpy(Temp->word, word);
    Temp->Next = NULL;

    if (List->head == NULL)
    {
        List->head = Temp;
        Array[val].tail = Temp;
        num_elems++;
    }

    else
    {
        Temp->Next = List->head;
        List->head = Temp;
        num_elems++;
    }

    collisions = count(List->head);

    return (collisions - 1);
}

int count(PtrToNode_2 List)
{
    int count = 0;
    while (List != NULL)
    {
        count++;
        List = List->Next;
    }

    return count;
}

void deleteTable_SC_2(Array_SC_2 Array, int table_size)
{
    for (int hash_val = 0; hash_val < table_size; hash_val++)
    {
        PtrToNode_2 List = (PtrToNode_2)Array[hash_val].head;
        if (List == NULL)
            continue;
        else
        {
            while (List->Next != NULL)
            {
                PtrToNode_2 delete_node = List->Next;
                PtrToNode_2 curr_node = List;

                curr_node->Next = delete_node->Next;
                free(delete_node);
            }
            free(List);
        }
    }
    free(Array);
}