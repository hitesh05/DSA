#ifndef __HASH_C
#define __HASH_C

//linear probing Question 1 and Question 2:
typedef struct HashTable_LP_1
{
    char word[32];
    long long int value;

} HashTable_LP;

typedef HashTable_LP *Array_LP;

void initArray_LP(Array_LP Array, int table_size);
int Insert_LP(Array_LP Array, long long int val, int num_elems, int table_size, char word[], int *probes);
int Find_LP(Array_LP Array, long long int val, int table_size, char word[]);
void deleteTable_LP(Array_LP Array);

//general funcs in Question 1:
unsigned int Hash_1(long long int val, int table_size);

//general funcs for ques 2:
unsigned int Horner(int string[], int n, int x, int table_size);
int fast_compare(const char *ptr0, const char *ptr1, int len);

#endif