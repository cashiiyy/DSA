#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *c = (int *)malloc(sizeof(int) * (high - low + 1));
    if (c == NULL) return;

    // Main comparison merge loop
    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            c[k++] = arr[i++];
        }
        else
        {
            c[k++] = arr[j++];
        }
    }

    // Cleanly copy any remaining elements from the left side
    while (i <= mid)
    {
        c[k++] = arr[i++];
    }

    // Cleanly copy any remaining elements from the right side
    while (j <= high)
    {
        c[k++] = arr[j++];
    }


    for (int m = 0; m < k; m++)
    {
        arr[low + m] = c[m];
    }

    free(c);
}

void mergesort(int arr[], int low, int high)
{
    if (high <= low) return;

    int mid = floor((low + high) / 2);
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int arr[10] = {7, 8, 5, 3, 9, 1, 2, 10, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
