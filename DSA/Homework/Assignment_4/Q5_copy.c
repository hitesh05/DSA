#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define SIZE 100007

//pointer method
//complexity = O(q*x) --> not the best solution

//can val not be a part of the array?

unsigned long int count;
int flag2; //to check repetitions

void readArray(long int Arr[], int num_elems)
{
    for (int i = 0; i < num_elems; i++)
    {
        scanf("%ld", &Arr[i]);
    }
}

int findSmallest(long int Arr[], int K)
{
    int min = Arr[0];
    for (int i = 1; i <= K; i++)
    {
        if (Arr[i] < min)
            min = Arr[i];
    }

    return min;
}

int findLargest(long int Arr[], int X, int K)
{
    int max = Arr[X];
    for (int i = X; i >= X - K; i--)
    {
        if (Arr[i] > max)
            max = Arr[i];
    }

    return max;
}

int findMin(long int Arr[], long int X, long int val)
{
    for (int i = X; i >= 0; i--)
    {
        if (Arr[i] < val)
            return i;
        else if (Arr[i] == val)
            flag2++;
        else
            count++;
    }
    return -1;
}

int main(void)
{
    int num_elems, num_queries, abs_diff;
    long int X, val;

    // printf("Enter num_elements, num_queries, and absolute_diff:\n");
    scanf("%d %d %d", &num_elems, &num_queries, &abs_diff);

    long int *Arr = (long int *)malloc(SIZE * sizeof(long int));
    assert(Arr != NULL);

    long int *Output = (long int *)malloc(SIZE * sizeof(long int));
    assert(Output != NULL);

    readArray(Arr, num_elems);

    for (int i = 0; i < num_queries; i++) //O(q*X)
    {
        flag2 = 0;
        scanf("%ld %ld", &X, &val);
        X--;
        // printf("X = %ld\n", X);

        int flag = 0;

        int smallest = findSmallest(Arr, abs_diff);

        if (smallest > val)
        {
            Output[i] = X + 1;
            flag = 1;
        }
        if (!flag)
        {
            int largest = findLargest(Arr, X, abs_diff);
            if (largest < val)
            {
                Output[i] = 0;
                flag = 1;
            }
        }

        if (!flag)
        {
            count = 0;
            int index = findMin(Arr, X, val);

            //printf("Index = %d\n", index);

            if (index == -1)
            {
                // printf("flag2 = %d\n X+1 = %ld\n", flag2, X + 1);

                Output[i] = X - flag2 + 1;
            }

            else
            {
                int a = (index - (2 * abs_diff) + 1);
                if (a < 0)
                    a = 0;
                //printf("a = %d\n", a);

                for (int j = (index - 1); j >= a; j--)
                {
                    if (Arr[j] > val)
                        count++;
                }

                Output[i] = count;
            }
        }

        // count += (X - index);
    }

    // printf("Output:\n");
    for (int i = 0; i < num_queries; i++)
    {
        printf("%ld\n", Output[i]);
    }

    free(Arr);
    free(Output);

    return 0;
}
