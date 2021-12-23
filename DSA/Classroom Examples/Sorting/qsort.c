#include <stdio.h>
#include <stdlib.h>

typedef struct names
{
    int n;
    char name[21];
} names;

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int N;
    scanf("%d", &N);

    names names;

    struct names *Arr = (struct names *)malloc(N * sizeof(struct names));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Arr[i].n);
        scanf("%s", Arr[i].name);
    }

    qsort(Arr, N, sizeof(struct names), cmpfunc);

    for (int i = 0; i < N; i++)
    {
        printf("%d %s\n", Arr[i].n, Arr[i].name);
    }

    return 0;
}