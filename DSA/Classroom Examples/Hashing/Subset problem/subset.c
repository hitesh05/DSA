#include <stdio.h>
#include <stdlib.h>
#include "subset.h"

int max_size = 10;
int num_elements = 0;

void initArray(Table Array)
{
    for (int i = 0; i < max_size; i++)
    {
        Array[i].NextPtr = NULL;
    }
}

int HashCode(int key)
{
    int hash_code = key % max_size;
    return hash_code;
}

void Insert(Table Array, int val)
{
    double alpha = 0; //load factor
    int hash_val = HashCode(val);

    PtrToNode List = (PtrToNode)Array[hash_val].NextPtr;

    PtrToNode Temp = (PtrToNode)malloc(sizeof(Node));
    Temp->value = val;
    Temp->NextPtr = NULL;

    if (List == NULL)
    {
        Array[hash_val].NextPtr = Temp;
        num_elements++;
    }

    else //insert at front
    {
        Temp->NextPtr = Array[hash_val].NextPtr;
        Array[hash_val].NextPtr = Temp;
        num_elements++;
    }

    alpha = num_elements / max_size;

    // if (alpha >3)
    //     rehash();
}
