#include <stdio.h>
#include <stdlib.h>

#define SIZE 10007
#define SIZE_2 10000007

void readArray(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
}

void findSum(int A[], int S[], int Freq[], int arr_elems, int sub_size)
{
    long int sum = 0;
    int j = 0;

    for (int i = 0; i < sub_size; i++)
    {
        sum += A[i];
    }
    S[j] = sum;
    Freq[sum % SIZE_2]++;
    j++;

    for (int i = sub_size; i < arr_elems; i++)
    {
        sum += A[i] - A[i - sub_size];
        S[j] = sum;
        Freq[sum % SIZE_2]++;
        j++;
    }
}

int main()
{

    int arr_elems, sub_size;
    long int sum;
    int z;
    long int count = 0;

    //printf("Enter the number of elements in the array and size of sub matrix(k*k)\n");
    scanf("%d", &arr_elems);
    if (arr_elems >= 10000)
    {
        printf("0\n");
        return 0;
    }

    int *A = (int *)calloc((arr_elems), sizeof(int));

    // printf("Input the array\n");
    readArray(A, arr_elems);

    // printf("Enter the sum to be found\n");
    scanf("%ld", &sum);

    for (int i = 1; i <= arr_elems; i++)
    {
        if (sum % i != 0)
        {
            continue;
        }

        sub_size = i;
        z = arr_elems - sub_size;
        int *S = (int *)calloc(SIZE, sizeof(int));
        int *Freq = (int *)calloc(SIZE_2, sizeof(int));

        findSum(A, S, Freq, arr_elems, sub_size);

        for (int i = 0; i < z + 1; i++)
        {
            long int x = sum / sub_size;
            long int val = x - S[i];
            if (val < 0)
            {
                continue;
            }
            count += Freq[val % SIZE_2];
        }
        free(Freq);
        free(S);
    }

    printf("%ld\n", count);
    free(A);

    return 0;
}