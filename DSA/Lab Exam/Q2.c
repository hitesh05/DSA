#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(long int *)a - *(long int *)b);
}

int main()
{
    long int N;
    scanf("%d", &N);

    long int A[2 * N];

    for (long int i = 0; i < 2 * N; i++)
    {
        scanf("%ld", &A[i]);
    }

    qsort(A, (2 * N), sizeof(long int), cmpfunc);

    long int B = 0;
    long int C = 0;

    for (int i = 0; i < N; i++)
    {
        B += A[i];
        C += A[i + N];
    }

    printf("%ld\n", (C - B));

    return 0;
}