#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX 1000007

typedef struct Node_1 Node_1;
typedef Node_1 *PtrToNode_1;

struct Node_1
{
    int value;
    PtrToNode_1 Next;
};

typedef struct HashTable_OC_1
{
    PtrToNode_1 head;
    PtrToNode_1 tail;

} HashTable_OC_1;

typedef HashTable_OC_1 *Array_OC_1;

void initArray_OC_1(Array_OC_1 Array, int table_size)
{
    for (int i = 0; i < table_size; i++)
    {
        Array[i].head = NULL;
        Array[i].tail = NULL;
    }
}

void Insert_OC_1(Array_OC_1 Array, int crp, int val)
{
    int hash_val = crp;

    PtrToNode_1 List = (PtrToNode_1)Array[hash_val].head;

    PtrToNode_1 Temp = (PtrToNode_1)malloc(sizeof(Node_1));
    Temp->value = val;
    Temp->Next = NULL;

    if (List == NULL)
    {
        Array[hash_val].head = Temp;
        Array[hash_val].tail = Temp;
    }

    else //insert at rear
    {
        Array[hash_val].tail->Next = Temp;
        Array[hash_val].tail = Temp;
    }
}

void Delete_OC_1(Array_OC_1 Array, int crp, int val)
{
    int hash_val = crp;

    PtrToNode_1 List = (PtrToNode_1)Array[hash_val].head;

    PtrToNode_1 deleteNode, currentNode;

    if (List == NULL)
    {
        return;
    }

    else
    {
        if (List->value == val)
        {
            deleteNode = List;
            List = List->Next;
            free(deleteNode);
        }
        else
        {
            while (List->Next)
            {

                if (List->Next->value == val)
                {
                    deleteNode = List->Next;
                    currentNode = List;

                    currentNode->Next = deleteNode->Next;
                    free(deleteNode);

                    break;
                }
                List = List->Next;
            }
        }
    }
}

void Find_OC_1(Array_OC_1 Array, int val, int crp, int *count1, int *count2, int maxCRP)
{
    int hash_val = crp;
    *count1 = 0;
    *count2 = 0;

    for (int i = (hash_val + 1); i <= maxCRP; i++)
    {
        PtrToNode_1 List = (PtrToNode_1)Array[i].head;

        if (List == NULL)
            continue;
        else
        {
            while (List != NULL)
            {
                *count2 = *count2 + 1;
                if (List->value > val)
                    *count1 = *count1 + 1;

                List = List->Next;
            }
        }
    }
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

int main()
{
    int num_queries;
    long int threshold;
    long int maxCRP = 0;

    scanf("%d %ld", &num_queries, &threshold);

    double *Output = (double *)malloc(sizeof(double) * num_queries);
    int z = 0;

    char b1[] = "+";
    char b2[] = "-";
    char b3[] = "?";

    char b4[2];

    Array_OC_1 Array1;

    Array1 = (Array_OC_1)malloc(MAX * sizeof(HashTable_OC_1));
    initArray_OC_1(Array1, MAX);

    for (int i = 0; i < num_queries; i++)
    {
        scanf("%s", b4);

        if (!strcmp(b1, b4))
        {
            long int crp, ct;
            scanf("%ld %ld", &crp, &ct);

            Insert_OC_1(Array1, crp, ct);

            if (crp > maxCRP)
                maxCRP = crp;
        }

        else if (!strcmp(b2, b4))
        {
            long int crp, ct;
            scanf("%ld %ld", &crp, &ct);

            Delete_OC_1(Array1, crp, ct);
        }
        else if (!strcasecmp(b3, b4))
        {
            int count1 = 0, count2 = 0;
            long int crp;
            scanf("%ld", &crp);

            Find_OC_1(Array1, threshold, crp, &count1, &count2, maxCRP);

            if (count1 == 0)
                Output[i] = 0;
            else
                Output[z] = (double)count1 / count2;

            z++;
        }
    }

    // deleteTable_OC_1(Array1, MAX);

    for (int i = 0; i < z; i++)
    {
        if (Output[i] == 0)
            printf("0\n");
        else
            printf("%f\n", Output[i]);
    }

    return 0;
}