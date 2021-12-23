#include <stdio.h>
#include <stdlib.h>

int countSort(int Arr[], int length)
{
    int count[n]; //N = RANGE --> STORE ACCORDING TO THE QUESTION

    int *X = (int *)calloc((length + 1), sizeof(int)); //array to store sorted elements

    // for (int i = 0; i < length; i++) //initialising
    // {
    //     X[i] = 0;
    // }

    for (int i = 1; i < 21; i++) //initialising
    {
        count[i] = 0;
    }

    for (int i = 0; i < length; i++) //maintaining the count array (step 1)
    {
        count[Arr[i]]++;
    }

    for (int i = 2; i < 21; i++) //updating the count array (step 2)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < length; i++) //writing sorted elements into array X
    {
        X[count[Arr[i]] - 1] = Arr[i];
        count[Arr[i]]--;
    }

    int median = X[length / 2];
    free(X);
    return (median);
}