#ifndef __HASH_C
#define __HASH_C

int table_size1 = 2003;
int table_size2 = 2003;

//open chaining Question 1:
typedef struct Node_1 Node_1;
typedef Node_1 *PtrToNode_1;

struct Node_1
{
    int value;
    PtrToNode_1 Next;
};

typedef struct HashTable_OC_1
{
    int garbage[1000000];
    PtrToNode_1 head;
    PtrToNode_1 tail;

} HashTable_OC_1;

typedef HashTable_OC_1 *Array_OC_1;

void initArray_OC_1(Array_OC_1 Array);
int Insert_OC_1(Array_OC_1 Array, int val, int num_elems);
int Find_OC_1(Array_OC_1 Array, int val);
void deleteTable_OC_1(Array_OC_1 Array);

//linear probing
typedef struct HashTable_LP_1
{
    int garbage[1000000];
    long long int value;

} HashTable_LP;

typedef HashTable_LP *Array_LP;

void initArray_LP(Array_LP Array);
int Insert_LP(Array_LP Array, int val, int num_elems);
int Find_LP(Array_LP Array, long long int val);
void deleteTable_LP(Array_LP Array);

//quadratic probing Question 1:
typedef struct HashTable_QP_1
{
    //int garbage[1000000];
    int value;

} HashTable_QP_1;

typedef HashTable_QP_1 *Array_QP_1;

void initArray_QP_1();
int Insert_QP_1(int val, int num_elems);
int Find_QP_1(int val);
Array_QP_1 rehash();
void deleteTable_QP_1();
int Hash_2(long long int val);
void initArray_QP_2(Array_QP_1 Temp, int size);

//general funcs in Question 1:
int Hash_1(long long int val);

#endif

Array_QP_1 Array3;
Array_QP_1 Temp;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//open chaining Question 1:
void initArray_OC_1(Array_OC_1 Array)
{
    for (int i = 0; i < table_size1; i++)
    {
        Array[i].head = NULL;
        Array[i].tail = NULL;
    }
}

int Hash_1(long long int val)
{
    return val % table_size1;
}

int Hash_2(long long int val)
{
    return val % table_size2;
}

int Insert_OC_1(Array_OC_1 Array, int val, int num_elems)
{
    double probes = 0;
    double alpha = 0; //load factor
    int hash_val = Hash_1(val);

    PtrToNode_1 List = (PtrToNode_1)Array[hash_val].head;

    PtrToNode_1 Temp = (PtrToNode_1)malloc(sizeof(Node_1));
    Temp->value = val;
    Temp->Next = NULL;
    //probes++;

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

    alpha = num_elems / table_size1;

    return probes;
}

void deleteTable_OC_1(Array_OC_1 Array)
{
    for (int hash_val = 0; hash_val < table_size1; hash_val++)
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
void initArray_LP(Array_LP Array)
{
    for (int i = 0; i < table_size1; i++)
    {
        Array[i].value = -1;
    }
}

int Insert_LP(Array_LP Array, int val, int num_elems)
{
    int hash_val = Hash_1(val);
    int probes = 0;
    //double alpha; //load factor

    if (Array[hash_val].value == -1) //empty slot found on first probe itself
    {
        Array[hash_val].value = val;
        probes++;
        num_elems++;
    }
    else //empty slot not found
    {
        for (int i = 1; i < table_size1; i++)
        {
            int hash_val_2 = (hash_val + i) % table_size1;
            probes++;

            if (Array[hash_val_2].value == -1)
            {
                Array[hash_val_2].value = val;
                num_elems++;
                break;
            }
        }
    }

    return probes;

    // alpha = num_elems / table_size;
}

void deleteTable_LP(Array_LP Array)
{
    free(Array);
}

//Quadratic Probing Question 1:
void initArray_QP_1()
{
    for (int i = 0; i < table_size2; i++)
    {
        Array3[i].value = -1;
    }
}

int Insert_QP_1(int val, int num_elems)
{
    int hash_val = Hash_2(val);
    int probes = 0;
    double alpha; //load factor

    if (Array3[hash_val].value == -1) //empty slot found on first probe itself
    {
        Array3[hash_val].value = val;
        probes++;
        num_elems++;
    }
    else //empty slot not found
    {
        for (int i = 1; i < table_size2; i++)
        {
            int hash_val_2 = (hash_val + i * i) % table_size2;
            probes++;

            if (Array3[hash_val_2].value == -1)
            {
                Array3[hash_val_2].value = val;
                num_elems++;
                break;
            }
        }
    }

    alpha = (double)num_elems / table_size2;
    if (alpha >= 0.5)
        Array3 = rehash();

    return probes;
}

// void initArray_QP_2(Array_QP_1 Temp, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         Temp[i].value = -1;
//     }
// }

Array_QP_1 rehash()
{
    table_size2 = 4003;

    for (int i = 0; i < 4003; i++)
    {
        Temp[i].value = -1;
    }

    //initArray_QP_2(Temp, table_size2);

    //Temp = Array3;

    for (int hash_val = 0; hash_val < table_size2; hash_val++)
    {
        if (Temp[hash_val].value == -1)
        {
            Temp[hash_val].value = Array3[hash_val].value;
        }
        else //empty slot not found
        {
            for (int i = 1; i < table_size2; i++)
            {
                hash_val = (hash_val + i * i) % table_size2;

                if (Temp[hash_val].value == -1)
                {
                    Temp[hash_val].value = Array3[hash_val].value;
                    break;
                }
            }
        }
    }
    free(Array3);

    return Temp;
}

void deleteTable_QP_1()
{
    free(Array3);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>

int main(void)
{
    double load_factor[] = {200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000}; //values for which we have to print

    time_t t;
    srand((unsigned)time(&t));

    //m runs:
    for (int m = 0; m < 5; m++)
    {
        int Even[2000] = {0}; //array of even integers
        int a = 0;

        for (int i = 0; i < 2000; i++)
        {
            int x = rand() % 1500; //limiting the range of even numbers so that more collisions
            if (x % 2 == 0)
            {
                Even[a] = x;
                a++;
            }
            else
            {
                Even[a] = x + 1;
                a++;
            }
        }
        //separate chaining
        Array_OC_1 Array1;

        int num_elems = 0;
        double probes_OC = 0;

        Array1 = (Array_OC_1)malloc(table_size1 * sizeof(HashTable_OC_1));
        initArray_OC_1(Array1);

        for (int i = 0; i < 2000; i++)
        {
            probes_OC += Insert_OC_1(Array1, Even[i], i + 1);

            // printf("%d ", Even[i] % table_size);
            for (int j = 0; j < 10; j++)
            {
                if (i == load_factor[j])
                {
                    printf("Separate Chaining probes[%.2f] = %.3f\n", (double)i / 2000, probes_OC / (i + 1));
                }
            }
        }

        deleteTable_OC_1(Array1);

        //Linear probing
        Array_LP Array2;
        double probes_LP = 0;

        Array2 = (Array_LP)malloc(table_size1 * sizeof(HashTable_LP));
        initArray_LP(Array2);

        for (int i = 0; i < 2000; i++)
        {
            probes_LP += Insert_LP(Array2, Even[i], i + 1);

            for (int j = 0; j < 10; j++)
            {
                if (i == load_factor[j])
                {
                    printf("Linear probes[%.2f] = %.3f\n", (double)i / 2000, probes_LP / (i + 1));
                }
            }
        }

        deleteTable_LP(Array2);

        //Quadratic probing:
        double probes_QP = 0;

        Array3 = (Array_QP_1)malloc(table_size2 * sizeof(HashTable_QP_1));
        assert(Array3 != NULL);

        Temp = (Array_QP_1)malloc(4003 * sizeof(HashTable_QP_1));
        assert(Temp != NULL);

        initArray_QP_1(Array3);

        for (int i = 0; i < 2000; i++)
        {
            probes_QP += Insert_QP_1(Even[i], i + 1);

            for (int j = 0; j < 5; j++)
            {
                if (i == load_factor[j])
                {
                    printf("Quadratic probes[%.2f] = %.3f\n", (double)i / 2000, probes_QP / (i + 1));
                }
            }
        }
        deleteTable_QP_1();
        printf("\n\n");
    }

    return 0;
}