#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[1100][1100];
int Median[600000];

#define SIZE 600000

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

int countSort(int B[], int count[], int count2[], int length) //for median of initial subarray  //runs in O(k^2)
{
    for (int i = 0; i < 21; i++) //initialising
    {
        count[i] = 0;
    }

    for (int i = 0; i < 21; i++) //initialising
    {
        count2[i] = 0;
    }

    for (int i = 0; i < length; i++) //maintaining the count array (step 1)
    {
        count[B[i]]++;
        count2[B[i]]++;
    }

    // printf("Count:\n");
    // for (int i = 0; i < 21; i++)
    // {
    //     printf("%d ", count[i]);
    // }
    // printf("\n");

    for (int i = 1; i < 21; i++) //updating the count array (step 2)
    {
        count2[i] += count2[i - 1];
    }

    int median;
    for (int i = 0; i < 21; i++)
    {
        if (count2[i] > (length / 2))
        {
            median = i;
            break;
        }
    }

    return median;
}

int countSort2(int count[], int count2[], int length) //for median of consequent subarrays //runs in constant time
{
    int median;

    for (int i = 0; i < 21; i++) //initialising
    {
        count2[i] = 0;
    }

    // printf("Count2:\n");
    for (int i = 0; i < 21; i++)
    {
        count2[i] = count[i];
        //printf("%d ", count2[i]);
    }
    // printf("\n");

    for (int i = 1; i < 21; i++) //updating the count array (step 2)
    {
        count2[i] += count2[i - 1];
    }

    for (int i = 0; i < 21; i++)
    {
        if (count2[i] > (length / 2))
        {
            median = i;
            break;
        }
    }

    return median;
}

void findArray(int B[], int i, int K) //finding subarrays starting at row 0
{
    int a = 0;

    for (int c = i; c < i + K; c++)
    {
        for (int r = 0; r < K; r++)
        {
            B[a] = A[r][c];
            a++;
        }
    }
}

// void printArray(int B[], int elems)
// {
//     printf("B: \n");
//     for (int i = 0; i < elems; i++)
//     {
//         printf("%d ", B[i]);
//     }
//     printf("\n");
// }

int main(void)
{
    int *B = (int *)malloc(SIZE * sizeof(int));
    int *Temp = (int *)malloc(SIZE * sizeof(int));

    int N, K;

    scanf("%d %d", &N, &K);
    int length = (K * K);

    int *count = (int *)calloc(21, sizeof(int));
    int *count2 = (int *)calloc(21, sizeof(int));
    int *count3 = (int *)calloc(21, sizeof(int));

    readArray(N);
    findArray(B, 0, K); //1st subarray
    //printArray(B, length);

    memcpy(Temp, B, (SIZE * sizeof(int)));
    // printf("Temp: \n");
    // for (int i = 0; i < length; i++)
    // {
    //     printf("%d ", B[i]);
    // }
    // printf("\n");

    int x = 0;
    Median[x] = countSort(B, count, count2, length);
    // printf("Median = %d\n", Median[x]);
    x++;

    memcpy(count3, count, (21 * sizeof(int)));

    int a = 0;
    int b = 0;

    for (int col = 0; col <= N - K; col++)
    {
        if (col != 0)
        {
            //a = K * (col - 1);
            for (int row = 0; row < K; row++)
            {
                count3[Temp[b]]--;
                Temp[b] = A[row][col + K - 1];
                count3[Temp[b]]++;

                b = (b + 1) % length;
            }
            // printf("Temp: \n");
            // for (int i = 0; i < length; i++)
            // {
            //     printf("%d ", B[i]);
            // }
            //printf("\n");
            memcpy(B, Temp, (SIZE * sizeof(int))); //constant time
            memcpy(count, count3, (21 * sizeof(int)));
            Median[x] = countSort2(count, count2, length);
            //  printArray(B, length);
            //  printf("Median = %d\n", Median[x]);
            x++;
        }
        a = 0;

        for (int i = 1; i <= N - K; i++)
        {
            //a++;
            for (int j = col; j < K + col; j++)
            {
                count[B[a]]--;
                B[a] = A[i + K - 1][j];
                count[B[a]]++;

                a = (a + K) % length;
            }
            //   printArray(B, length);

            Median[x] = countSort2(count, count2, length);
            // printf("Median = %d\n", Median[x]);
            x++;
            a++;
        }
    }

    a = 0;
    for (int j = 0; j <= N - K; j++)
    {
        for (int i = 0; i <= N - K; i++)
        {
            printf("%d ", Median[a]);
            a++;
        }
        printf("\n");
    }

    free(B);
    free(Temp);
    free(count);
    free(count2);
    free(count3);

    return 0;
}