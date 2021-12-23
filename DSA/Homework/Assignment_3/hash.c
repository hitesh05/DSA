#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

//open chaining Question 1:
void initArray_OC_1(Array_OC_1 Array, int table_size)
{
    for (int i = 0; i < table_size; i++)
    {
        Array[i].head = NULL;
        Array[i].tail = NULL;
    }
}

int Hash_1(long long int val, int table_size)
{
    return val % table_size;
}

void Insert_OC_1(Array_OC_1 Array, int val, int num_elems, int table_size)
{
    double probes = 0;
    double alpha = 0; //load factor
    int hash_val = Hash_1(val, table_size);

    PtrToNode_1 List = (PtrToNode_1)Array[hash_val].head;

    PtrToNode_1 Temp = (PtrToNode_1)malloc(sizeof(Node_1));
    Temp->value = val;
    Temp->Next = NULL;

    if (List == NULL)
    {
        Array[hash_val].head = Temp;
        Array[hash_val].tail = Temp;
        probes++;
        num_elems++;
    }

    else //insert at rear
    {
        Array[hash_val].tail->Next = Temp;
        Array[hash_val].tail = Temp;
        probes++;
        num_elems++;
    }

    alpha = num_elems / table_size;
}

int Find_OC_1(Array_OC_1 Array, int val, int table_size)
{
    int hash_val = Hash_1(val, table_size);
    int count = 0;

    PtrToNode_1 List = (PtrToNode_1)Array[hash_val].head;

    if (List == NULL)
        return -1;
    else
    {
        while (List != NULL)
        {
            if (List->value == val)
                return count;
            else
            {
                count++;
                List = List->Next;
            }
        }
    }

    return -1; //element not found
}

void deleteTable_OC_1(Array_OC_1 Array, int table_size)
{
    for (int hash_val = 0; hash_val < table_size; hash_val++)
    {
        PtrToNode_1 List = (PtrToNode_1)Array[hash_val].head;
        if (List == NULL)
            continue;
        else
        {
            while (List->Next != NULL)
            {
                PtrToNode_1 delete_node = List->Next;
                PtrToNode_1 curr_node = List;

                curr_node->Next = delete_node->Next;
                free(delete_node);
            }
            free(List);
        }
    }
    free(Array);
}

//Linear Probing Question 1 and Question 2:
void initArray_LP(Array_LP Array, int table_size)
{
    for (int i = 0; i < table_size; i++)
    {
        Array[i].value = -1;
    }
}

Array_LP Insert_LP(Array_LP Array, long long int val, int num_elems, int table_size)
{
    int hash_val = Hash_1(val, table_size);
    //int probes = 0;
    //double alpha; //load factor

    if (Array[hash_val].value == -1) //empty slot found on first probe itself
    {
        Array[hash_val].value = val;
        // probes++;
        num_elems++;
    }
    else //empty slot not found
    {
        for (int i = 1; i < table_size; i++)
        {
            int hash_val_2 = (hash_val + i) % table_size;
            // probes++;

            if (Array[hash_val_2].value == -1)
            {
                Array[hash_val_2].value = val;
                num_elems++;
                break;
            }
        }
    }

    return Array;

    // alpha = num_elems / table_size;
}

int Find_LP(Array_LP Array, long long int val, int table_size)
{
    int hash_val = Hash_1(val, table_size);

    if (Array[hash_val].value == -1)
        return -1;
    else
    {
        if (Array[hash_val].value == val)
            return hash_val;
        else
        {
            for (int i = 1; i < table_size; i++)
            {
                hash_val = (hash_val + 1) % table_size;

                if (Array[hash_val].value == val)
                    return hash_val;
            }
        }
    }
    return -1;
}

void deleteTable_LP(Array_LP Array)
{
    free(Array);
}

//Quadratic Probing Question 1:
void initArray_QP_1(Array_QP_1 Array, int table_size)
{
    for (int i = 0; i < table_size; i++)
    {
        Array[i].value = -1;
    }
}

void Insert_QP_1(Array_QP_1 Array, int val, int num_elems, int table_size)
{
    int hash_val = Hash_1(val, table_size);
    int probes = 0;
    double alpha; //load factor

    if (Array[hash_val].value == -1) //empty slot found on first probe itself
    {
        Array[hash_val].value = val;
        probes++;
        num_elems++;
    }
    else //empty slot not found
    {
        for (int i = 1; i < table_size; i++)
        {
            int hash_val_2 = (hash_val + i * i) % table_size;
            probes++;

            if (Array[hash_val_2].value == -1)
            {
                Array[hash_val_2].value = val;
                num_elems++;
                break;
            }
        }
    }

    // alpha = (double)num_elems / table_size;
    // if (alpha >= 0.5)
    //     rehash(Array, table_size);

    //return probes;
}

int Find_QP_1(Array_QP_1 Array, int val, int table_size)
{
    int hash_val = Hash_1(val, table_size);

    if (Array[hash_val].value == -1)
        return -1;
    else
    {
        if (Array[hash_val].value == val)
            return hash_val;
        else
        {
            for (int i = 1; i < table_size; i++)
            {
                int hash_val_2 = (hash_val + i * i) % table_size;

                if (Array[hash_val_2].value == val)
                    return hash_val_2;
            }
        }
    }
    return -1;
}

void deleteTable_QP_1(Array_QP_1 Array)
{
    free(Array);
}

void rehash(Array_QP_1 *Array, int table_size)
{
    table_size = (2 * table_size);

    *Array = (Array_QP_1)realloc(*Array, table_size * sizeof(HashTable_QP_1));

    for (int i = table_size / 2; i < table_size; i++)
    {
        Array[i]->value = -1;
    }

    // initArray_QP_1(Array, table_size);
    // Array_QP_1 Temp = Array;

    // for (int hash_val = 0; hash_val < table_size; hash_val++)
    // {
    //     if (Temp[hash_val].value == -1)
    //     {
    //         Temp[hash_val].value = Array[hash_val].value;
    //     }
    //     else //empty slot not found
    //     {
    //         for (int i = 1; i < table_size; i++)
    //         {
    //             hash_val = (hash_val + i * i) % table_size;

    //             if (Temp[hash_val].value == -1)
    //             {
    //                 Temp[hash_val].value = Array[hash_val].value;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // free(Array);
}

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

void Insert_SC_2(Array_SC_2 Array, int val, int num_elems, int table_size, char word[]) //ERRORS.
{
    // double alpha = 0; //load factor
    // int hash_val = Hash_1(val, table_size);

    Array_SC_2 List = &Array[val];

    PtrToNode_2 Temp = (PtrToNode_2)malloc(sizeof(Node_2));

    Temp->value = val;
    strcpy(Temp->word, word);
    Temp->Next = NULL;

    if (List->head == NULL)
    {
        List->head = Temp;
        //Array[hash_val].tail = Temp;
        num_elems++;
    }

    else
    {
        Temp->Next = List->head;
        List->head = Temp;
        num_elems++;
    }

    // alpha = num_elems / table_size;
}

int Find_SC_2(Array_SC_2 Array, int val, int table_size, char word[])
{
    // int hash_val = Hash_1(val, table_size);

    PtrToNode_2 List = (PtrToNode_2)Array[val].head;

    if (List == NULL)
        return -1;
    else
    {
        while (List != NULL)
        {
            if (!(strcmp(List->word, word)))
                return 1;
            else
                List = List->Next;
        }
    }

    return -1; //element not found
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