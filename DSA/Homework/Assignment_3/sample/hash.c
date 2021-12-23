#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

//Linear Probing Question 1 and Question 2:
void initArray_LP(Array_LP Array, int table_size)
{
    for (int i = 0; i < table_size; i++)
    {
        Array[i].value = -1;
    }
}

int Insert_LP(Array_LP Array, long long int val, int num_elems, int table_size, char word[], int *probes)
{
    //HashTable_LP Htable1 = Array[val];
    // int val_2;
    // HashTable_LP Htable2 = Array[val_2];

    if (Array[val].value == -1) //empty slot found on first probe itself
    {
        Array[val].value = val;
        strcpy(Array[val].word, word);
        num_elems++;
    }
    else //empty slot not found
    {
        for (int i = 1; i < table_size; i++)
        {
            val = (val + 101 * i) % table_size;
            *probes++;

            if (Array[val].value == -1)
            {
                Array[val].value = val;
                strcpy(Array[val].word, word);
                num_elems++;
                break;
            }
        }
    }

    return *probes;

    // Array[val].value = Htable1.value;
    // strcpy(Array[val].word, Htable1.word);
}

int Find_LP(Array_LP Array, long long int val, int table_size, char word[])
{
    //  int hash_val = Hash_1(val, table_size);
    //HashTable_LP Htable1 = Array[val];

    if (Array[val].value == -1)
        return -1;
    else
    {
        if (strcmp(Array[val].word, word) == 0)
            return val;
        else
        {
            for (int i = 1; i < table_size; i++)
            {
                val = (val + 13 * i) % table_size;

                if (strcmp(Array[val].word, word) == 0)
                //if (fast_compare(Array[val].word, word, 32) == 0)
                {
                    return val;
                }
            }
        }
    }
    return -1;
}

void deleteTable_LP(Array_LP Array)
{
    free(Array);
}

unsigned int Horner(int string[], int n, int x, int table_size)
{
    unsigned long long int result = string[0];
    for (int i = 1; i < n; i++)
        result = result * x + string[i];

    return result % table_size;
}