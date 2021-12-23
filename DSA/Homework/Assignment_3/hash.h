#ifndef __HASH_C
#define __HASH_C

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
    //int garbage[1000000];
    PtrToNode_1 head;
    PtrToNode_1 tail;

} HashTable_OC_1;

typedef HashTable_OC_1 *Array_OC_1;

void initArray_OC_1(Array_OC_1 Array, int table_size);
void Insert_OC_1(Array_OC_1 Array, int val, int num_elems, int table_size);
int Find_OC_1(Array_OC_1 Array, int val, int table_size);
void deleteTable_OC_1(Array_OC_1 Array, int table_size);

//linear probing Question 1 and Question 2:
typedef struct HashTable_LP_1
{
    // int garbage[1000000];
    long long int value;

} HashTable_LP;

typedef HashTable_LP *Array_LP;

void initArray_LP(Array_LP Array, int table_size);
Array_LP Insert_LP(Array_LP Array, long long int val, int num_elems, int table_size);
int Find_LP(Array_LP Array, long long int val, int table_size);
void deleteTable_LP(Array_LP Array);

//quadratic probing Question 1:
typedef struct HashTable_QP_1
{
    //int garbage[1000000];
    int value;

} HashTable_QP_1;

typedef HashTable_QP_1 *Array_QP_1;

void initArray_QP_1(Array_QP_1 Array, int table_size);
void Insert_QP_1(Array_QP_1 Array, int val, int num_elems, int table_size);
int Find_QP_1(Array_QP_1 Array, int val, int table_size);
void rehash(Array_QP_1 *Array, int table_size);
void deleteTable_QP_1(Array_QP_1 Array);

//general funcs in Question 1:
int Hash_1(long long int val, int table_size);

//separate chaining Question 2:
typedef struct Node_2 Node_2;
typedef Node_2 *PtrToNode_2;

struct Node_2
{
    long long int value;
    char word[32];
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
unsigned int Horner(int string[], int n, int x,int table_size);

#endif