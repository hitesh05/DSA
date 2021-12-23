#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define SIZE 100007

void readArray(long int Arr[], int num_elems)
{
    for (int i = 0; i < num_elems; i++)
    {
        scanf("%ld", &Arr[i]);
    }
}

void merge(long int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
	are any because all the elements in the right sub array may get filled up first, and we'll exit out of the while loop*/
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
	are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(long int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int b_search(int beg, int end, long int A[], int n) //finding the left most element
{

    while (beg <= end)
    {

        int mid = beg + (end - beg) / 2;

        if (A[mid] == n)
        {
            if (mid + 1 < end + 1 && A[mid + 1] == n)
            {
                beg = mid + 1;
                continue;
            }
            else
                return mid;
        }

        else if (A[mid] < n)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return beg;
}

int main(void)
{
    int num_elems, num_queries, abs_diff;
    long int X, val;

    // printf("Enter num_elements, num_queries, and absolute_diff:\n");
    scanf("%d %d %d", &num_elems, &num_queries, &abs_diff);

    long int *Arr = (long int *)malloc(SIZE * sizeof(long int));
    assert(Arr != NULL);

    long int *Temp = (long int *)malloc(SIZE * sizeof(long int));

    long int *Output = (long int *)malloc(SIZE * sizeof(long int));
    assert(Output != NULL);

    readArray(Arr, num_elems);

    for (int i = 0; i < num_elems; i++)
    {
        Temp[i] = Arr[i];
    }

    mergeSort(Temp, 0, num_elems - 1);

    for (int i = 0; i < num_queries; i++)
    {
        scanf("%ld %ld", &X, &val);
        X--;

        unsigned long int count = 0;

        int index = b_search(0, num_elems - 1, Temp, val);

        int a = index - abs_diff;
        if (a < 0)
            a = 0;

        int b = index + abs_diff;
        if (b > X)
            b = X;

        for (int j = a; j <= b; j++)
        {
            if (Arr[j] > val)
                count++;
        }
        if (b < X)
        {
            count += X - b;
        }
        Output[i] = count;
        //}
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
