#include <stdio.h>
#include <stdlib.h>

#define SIZE 100001
#define SIZE_2 10000001

void readArray(unsigned int A[], unsigned int N)
{
    for (int i = 0; i < N; i++)
    {
        scanf("%u", &A[i]);
    }
}

void findSum(unsigned int A[], unsigned int S[], unsigned int arr_elems, unsigned int sub_size)
{
    unsigned long int sum = 0;
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

void findFreq(unsigned int S[], unsigned int Freq[], unsigned int elems)
{
    for (int i = 0; i < elems; i++)
    {
        Freq[S[i]]++;
    }
}

int main()
{
    unsigned int *A = (unsigned int *)malloc(SIZE * sizeof(unsigned int));
    unsigned int *S = (unsigned int *)malloc(SIZE * sizeof(unsigned int));
    unsigned int *Freq = (unsigned int *)calloc(SIZE_2, sizeof(unsigned int));

    unsigned int arr_elems, sub_size;
    unsigned long long int sum;
    unsigned int z = arr_elems - sub_size;
    unsigned long long int count = 0;

    //printf("Enter the number of elements in the array and size of sub matrix(k*k)\n");
    scanf("%u %u", &arr_elems, &sub_size);
    z = arr_elems - sub_size;

    // printf("Input the array\n");
    readArray(A, arr_elems);

    // printf("Enter the sum to be found\n");
    scanf("%lld", &sum);

    findSum(A, S, arr_elems, sub_size);

    findFreq(S, Freq, z + 1);

    for (int i = 0; i < z + 1; i++)
    {
        unsigned long int x = sum / sub_size;
        unsigned long int val = x - S[i];

        if (Freq[val] != 0)
            count += Freq[val];
    }

    // int k = 0;
    // for (int i = 0; i < z + 1; i++)   //complexity = O(n^2)  --> doesen't work for large cases.
    // {
    //     for (int j = 0; j < z + 1; j++)
    //     {
    //         unsigned long long int x = (sub_size) * (S[i] + S[j]);

    //         // int xd = x / sub_size;
    //         if (x == sum)
    //             count++;
    //     }
    // }

    printf("%lld\n", count);

    free(A);
    free(S);
    free(Freq);

    //code for input:
    // printf("%d %d\n", 99999, 33);
    // for (int i = 0; i < 99999; i++)
    // {
    //     printf("%d ", i);
    // }
    // printf("\n");
    // printf("%d\n", 156987);

    return 0;
}