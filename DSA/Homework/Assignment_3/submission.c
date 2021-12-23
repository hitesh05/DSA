#ifndef __HASH_C
#define __HASH_C

//separate chaining Question 2:
typedef struct Node_2 Node_2;
typedef Node_2 *PtrToNode_2;

struct Node_2
{
    //long long int value;
    char word[33];
    PtrToNode_2 Next;
};

typedef struct HashTable_SC_2
{
    PtrToNode_2 head;
    PtrToNode_2 tail;

} HashTable_SC_2;

typedef HashTable_SC_2 *Array_SC_2;

void initArray_SC_2(Array_SC_2 Array, int table_size);
void Insert_SC_2(Array_SC_2 Array, int val, int num_elems, int table_size, char word[]);
int Find_SC_2(Array_SC_2 Array, int val, int table_size, char word[]);
void deleteTable_SC_2(Array_SC_2 Array, int table_size);
void rehash(); //try to implement if time is left. will also need a "next_prime" function.

//general funcs foe ques 2:
unsigned int Horner(int string[], int n, int x, int table_size);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

void Insert_SC_2(Array_SC_2 Array, int val, int num_elems, int table_size, char word[])
{
    Array_SC_2 List = &Array[val];

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char final_str[100001][33];
Array_SC_2 Array1;

int main(void)
{
    char *str = (char *)malloc(33 * sizeof(char));
    for (int i = 0; i < 33; i++)
    {
        str[i] = '\0';
    }
    int *string = (int *)calloc(33, sizeof(int));

    int table_size = 9973;

    int num_words;

    Array1 = (Array_SC_2)malloc(table_size * sizeof(HashTable_SC_2));
    assert(Array1 != NULL);
    initArray_SC_2(Array1, table_size);

    scanf("%d", &num_words);

    for (int i = 0; i < num_words; i++)
    {
        scanf("%s", str);

        int strln = strlen(str);
        for (int j = 0; j < strln; j++)
        {
            if (str[j] >= 'a' && str[j] <= 'z')
                string[j] = str[j] - 'a';
            else
                string[j] = str[j] - 'A';
        }

        unsigned int value = Horner(string, strln, 33, table_size);
        Insert_SC_2(Array1, value, i + 1, table_size, str);
    }

    //searching for words:
    int num_words_2;
    scanf("%d", &num_words_2);

    long int count = 0;
    for (int i = 0; i < num_words_2; i++)
    {
        scanf("%s", str);

        int strln = strlen(str);
        for (int j = 0; j < strln; j++)
        {
            if (str[j] >= 'a' && str[j] <= 'z')
                string[j] = str[j] - 'a';
            else if (str[j] >= 'A' && str[j] <= 'Z')
                string[j] = str[j] - 'A';
        }

        unsigned int value = Horner(string, strln, 33, table_size);
        int x = Find_SC_2(Array1, value, table_size, str);
        if (x == -1)
        {
            for (int z = 0; z < strln; z++)
            {
                final_str[count][z] = str[z];
            }
            count++;
        }
    }
    printf("%ld\n", count);

    for (int i = 0; i < count + 1; i++)
    {
        for (int z = 0; z < 32; z++)
        {
            if (((char)final_str[i][z] >= 'a' && (char)final_str[i][z] <= 'z') || ((char)final_str[i][z] >= 'A' && (char)final_str[i][z] <= 'Z'))
                printf("%c", (char)final_str[i][z]);
        }
        printf("\n");
    }

    deleteTable_SC_2(Array1, table_size);

    return 0;
}