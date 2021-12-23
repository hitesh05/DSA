#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100007

int main()
{
    int num_queries;
    scanf("%d", &num_queries);

    int *Freq = (int *)malloc(MAX * sizeof(int));
    int *Output = (int *)malloc(sizeof(int) * num_queries);

    for (int i = 0; i < MAX; i++)
    {
        Freq[i] = 0;
    }

    int op, num;

    for (int i = 0; i < num_queries; i++)
    {
        scanf("%d %d", &op, &num);

        if (op == 1)
        {
            Freq[num]++;
        }
        else
        {
            Freq[num]--;
        }

        for (int j = 0; j < MAX; j++)
        {
            if (Freq[j] == 0)
            {
                Output[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < num_queries; i++)
    {
        printf("%d ", Output[i]);
    }
    printf("\n");

    free(Freq);
    free(Output);

    return 0;
}