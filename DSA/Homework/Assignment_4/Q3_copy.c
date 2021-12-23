#include <stdio.h>
#include <stdlib.h>

int A[1000][1000];
int Median[251100];

void readArray(int N)
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}

int countSort(int Arr[], int length)
{
    int count[21]; //range = 0->21

    int *X = (int *)calloc((length + 1), sizeof(int)); //array to store sorted elements

    for (int i = 0; i < length; i++) //initialising
    {
        X[i] = 0;
    }

    for (int i = 1; i < 21; i++) //initialising
    {
        count[i] = 0;
    }

    for (int i = 0; i < length; i++) //maintaining the count array (step 1)
    {
        count[Arr[i]]++;
    }

    for (int i = 2; i < 21; i++) //updating the count array (step 2)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < length; i++) //writing sorted elements into array X
    {
        X[count[Arr[i]] - 1] = Arr[i];
        count[Arr[i]]--;
    }

    int median = X[length / 2];
    free(X);
    return (median);
}

int findArray(int i, int j, int K)
{
    int a = 0;
    int *B = (int *)calloc(251100, sizeof(int));

    for (int c = j; c < j + K; c++)
    {
        for (int r = i; r < i + K; r++)
        {
            B[a] = A[r][c];
            a++;
        }
    }

    int length = K * K;
    int median = countSort(B, length);
    free(B);
    return median;
}

int main(void)
{
    int N, K;
    int elem = 0;

    scanf("%d %d", &N, &K);

    readArray(N);

    for (int j = 0; j < K; j++)
    {
        for (int i = 0; i < K; i++)
        {
            int median = findArray(i, j, K); //constructing the submatrix in 1D and calculating median using Count Sort.

            Median[elem] = median;
            elem++;
        }
    }

    elem = 0;
    for (int j = 0; j < K; j++)
    {
        for (int i = 0; i < K; i++)
        {
            printf("%d ", Median[elem]);
            elem++;
        }
        printf("\n");
    }

    // printf("%d %d\n", 999, 450);
    // for (int i = 1; i < 1000; i++)
    // {
    //     for (int j = 1; j < 999; j++)
    //     {
    //         printf("1 ");
    //     }
    //     printf("\n");
    // }

    return 0;
}