#include <stdio.h>
#include <stdlib.h>

int A[1000][1000];
int B[251100];
int Median[251100];

void swap(int *M, int *N)
{
    int Temp;
    Temp = *M;
    *M = *N;
    *N = Temp;
}

int Left(int i)
{
    return ((2 * i) + 1);
}

int Right(int i)
{
    return ((2 * i) + 2);
}

int Parent(int i)
{
    return (i / 2);
}

void heapify(int A[], int length, int root)
{
    int largest = root;
    int l_child = Left(root);  //index of left child
    int r_child = Right(root); //index of right child

    //  int length = (sizeof(A) / sizeof(A[0]));

    if (l_child < length && A[l_child] > A[root])
        largest = l_child; //if left child > root; largest = left child

    if (r_child < length && A[r_child] > A[largest])
        largest = r_child; //if right child > largest; largest = right child

    if (largest != root)
    {
        swap(&A[root], &A[largest]);
        heapify(A, length, largest); //recursive call
    }
}

void buildMaxHeap(int A[], int n) //n = heapsize
{
    int a = ((n / 2) - 1);

    for (int i = a; i >= 0; i--)
    {
        heapify(A, n, i);
    }
}

void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to insert a new node to the Heap
void insertNode(int arr[], int *n, int Key)
{
    // Increase the size of Heap by 1
    *n = *n + 1;

    // Insert the element at end of Heap
    arr[*n - 1] = Key;

    swap(&arr[0], &arr[*n - 1]);

    // Heapify the new node
    heapify(arr, *n, 0);

    printf("Heap after insert: \n");
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteNode(int arr[], int *n, int key)
{
    //int delete = *key;
    int j;
    for (j = 0; j < *n; j++)
    {
        if (arr[j] == key)
            break;
    }

    swap(&arr[j], &arr[*n - 1]);
    *n = *n - 1;
    if (j < *n)
        swap(&arr[0], &arr[j]);

    heapify(arr, *n, 0);

    printf("Heap after delete: \n");
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}