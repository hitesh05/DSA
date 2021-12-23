#include <stdio.h>
#include <stdlib.h>
#define FREQ 10000001
#define SIZE 100001

void summer(int A[], int A1[], int n, int k, int hash[])
{
    int sum = 0;
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        sum += A[i];
    }
    A1[j] = sum;
    j++;
    for (int i = k; i < n; i++)
    {
        sum += A[i] - A[i - k];
        A1[j] = sum;
        j++;
    }
    for (int i = 0; i < n - k + 1; i++)
    {
        hash[(A1[i]) % FREQ]++;
    }
}

int main()
{
    int A[100001];

    int n, k;
    int sum;
    int count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d", &sum);
    for (int k = 1; k < n + 1; k++)
    {
        if (sum % k == 0)
        {

            int *A1 = (int *)calloc(100001, 4);

            int *hash = (int *)calloc(FREQ, 4);
            int sum1 = sum / k;
            summer(A, A1, n, k, hash);

            for (int i = 0; i < n - k + 1; i++)
            {
                if (sum1 - A1[i] >= 0 && hash[sum1 - A1[i]] > 0)
                {
                    count += hash[(sum1 - A1[i]) % FREQ];
                }
            }
            free(A1);
            free(hash);
        }
    }

    printf("%d\n", count);
    return 0;
}