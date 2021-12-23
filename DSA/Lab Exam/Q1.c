#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char state[3];
    int PVC;
    int AC;
    int MVC;
    int KC;
} Node;

struct node
{
    int n;
    char state[3];
};

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int num_states;
    scanf("%d", &num_states);

    struct Node *Arr = (struct Node *)malloc(num_states * sizeof(Node));
    struct node B[29];

    for (int i = 0; i < num_states; i++)
    {
        scanf("%s %d %d %d %d", Arr[i].state, &Arr[i].PVC, &Arr[i].AC, &Arr[i].MVC, &Arr[i].KC);

        B[i].n = (Arr[i].PVC * 1000) + (Arr[i].AC * 100) + (Arr[i].MVC * 10) + (Arr[i].KC);
        strcpy(B[i].state, Arr[i].state);
    }

    qsort(B, num_states, sizeof(struct node), cmpfunc);

    for (int i = num_states - 1; i >= 0; i--)
    {
        printf("%s ", B[i].state);
    }
    printf("\n");

    free(Arr);

    return 0;
}