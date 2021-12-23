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
int Insert_SC_2(Array_SC_2 Array, int val, int num_elems, int table_size, char word[]);
void deleteTable_SC_2(Array_SC_2 Array, int table_size);
int count(PtrToNode_2 List);

//general funcs foe ques 2:
unsigned int Horner(int string[], int n, int x, int table_size);

#endif