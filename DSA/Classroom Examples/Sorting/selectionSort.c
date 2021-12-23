#include <stdio.h>

// sorting by finding the min value of the array and then recursing.

#define ARRAY_SIZE 1000

int readArray(int A[])
{
    int i = 0;
    while (i < ARRAY_SIZE && scanf("%d", &A[i]) != EOF)
    {
        i += 1;
    }
    return i;
}

void swap(int *a, int *b)
{
    int x;

    x = *a;
    *a = *b;
    *b = x;
}

void selection_sort(int size, int A[size])
{
    if (size == 0)
    {
        return;
    }

    int min;

    for (int i = 0; i < size; ++i)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (A[j] < A[min])
                min = j;
        }

        swap(&A[min], &A[i]);
    }
}

int main()
{
    int A[ARRAY_SIZE], size;

    size = readArray(A);

    selection_sort(size, A);

    printf("In sorted order: \n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d\n", A[i]);
    }
}