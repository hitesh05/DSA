#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 100001

typedef struct HashTable
{
    long long int sum;
    unsigned long long int frequency;
} HashTable_LP;

typedef HashTable_LP *HashTable;

void initArray(HashTable Table, int size)
{
    for (int i = 0; i < size; i++)
    {
        Table[i].frequency = 0;
        Table[i].sum = -1;
    }
}

unsigned int Hash(long long int sum, int table_size)
{
    return sum % table_size;
}

void Insert(HashTable Table, long long int sum, int table_size)
{
    unsigned int hash_val = Hash(sum, table_size);

    if (Table[hash_val].sum == -1 || Table[hash_val].sum == sum)
    {
        Table[hash_val].sum = sum;
        Table[hash_val].frequency++;
    }

    else
    {
        for (int i = 1; i < table_size; i++)
        {
            unsigned int hash_val2 = (hash_val + i * i) % table_size;

            if (Table[hash_val2].sum == -1 || Table[hash_val2].sum == sum)
            {
                Table[hash_val2].sum = sum;
                Table[hash_val2].frequency++;
                break;
            }
        }
    }
}

int Find(HashTable Array, long long int sum, int table_size)
{
    int hash_val = Hash(sum, table_size);

    if (Array[hash_val].sum == -1)
        return -1;
    else
    {
        if (Array[hash_val].sum == sum)
            return hash_val;
        else
        {
            for (int i = 1; i < table_size; i++)
            {
                unsigned int hash_val2 = (hash_val + i * i) % table_size;

                if (Array[hash_val2].sum == sum)
                    return hash_val2;
            }
        }
    }
    return -1;
}

void readArray(unsigned int A[], unsigned int N)
{
    for (int i = 0; i < N; i++)
    {
        scanf("%u", &A[i]);
    }
}

int findFactors(unsigned int Factors[], long long int sum, unsigned int arr_elems)
{
    int j = 0;
    for (int i = 1; i <= arr_elems; i++)
    {
        if (sum % i == 0)
        {
            Factors[j] = i;
            j++;
        }
    }

    return (j);
}

void findSum(unsigned int A[], long long int S[], unsigned int arr_elems, unsigned int sub_size)
{
    long long int sum = 0;
    int j = 0;

    for (int i = 0; i < sub_size; i++)
    {
        sum += A[i];
    }
    S[j] = sum;
    j++;

    for (int i = sub_size; i < arr_elems; i++)
    {
        sum += A[i] - A[i - sub_size];
        S[j] = sum;
        j++;
    }
}

void findFreq(long long int S[], HashTable Freq, unsigned int elems)
{
    for (int i = 0; i < elems; i++)
    {
        unsigned long long int sum = S[i];
        Insert(Freq, sum, SIZE);
    }
}

int main()
{
    unsigned int *A = (unsigned int *)malloc(SIZE * sizeof(unsigned int));
    assert(A != NULL);

    unsigned int *Factors = (unsigned int *)calloc(SIZE, sizeof(unsigned int));
    assert(Factors != NULL);

    unsigned int arr_elems, sub_size;
    long long int sum;
    unsigned int z = arr_elems - sub_size;
    unsigned long long int count = 0;

    //printf("Enter the number of elements in the array and size of sub matrix(k*k)\n");
    scanf("%u", &arr_elems);

    // printf("Input the array\n");
    readArray(A, arr_elems);

    // printf("Enter the sum to be found\n");
    scanf("%lld", &sum);

    unsigned int size_Fac = findFactors(Factors, sum, arr_elems);

    for (unsigned int i = 0; i < size_Fac; i++)
    {
        sub_size = Factors[i];
        z = arr_elems - sub_size;

        long long int *S = (long long int *)malloc((SIZE) * sizeof(long long int));
        assert(S != NULL);

        HashTable Freq = (HashTable)malloc(SIZE * sizeof(HashTable_LP));
        assert(Freq != NULL);

        initArray(Freq, SIZE);

        findSum(A, S, arr_elems, sub_size);
        findFreq(S, Freq, z + 1);

        for (unsigned int j = 0; j < z + 1; j++)
        {
            long long int x = sum / sub_size;
            long long int val = (long long int)(x - S[j]);
            int hash_val;

            if (val < 0)
            {
                continue;
            }
            else
            {
                hash_val = Find(Freq, val, SIZE);
                if (hash_val >= 0)
                {
                    count += Freq[hash_val].frequency;
                }
            }
        }

        free(S);
        free(Freq);
    }

    printf("%lld\n", count);

    free(A);
    free(Factors);

    return 0;
}