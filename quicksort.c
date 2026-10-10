#include <stdio.h>
void quicksort(int a[], int f, int l)
{
    int pivot, i, j, temp;

    // Only sort if there are at least two elements
    if (f < l)
    {
        pivot = f;
        i = f;
        j = l;

        while (i < j)
        {
            // Move right as long as elements are smaller than or equal to pivot
            while (a[i] <= a[pivot] && i < l)
            {
                i++;
            }
            // Move left as long as elements are greater than pivot
            while (a[j] > a[pivot])
            {
                j--;
            }

            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // Swap the pivot element into its correct sorted position (at index j)
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        // Recursively sort the left and right partitions
        quicksort(a, f, j - 1);
        quicksort(a, j + 1, l);
    }
}

int main()
{
    int arr[] = {7, 8, 5, 3, 9, 1, 2, 10, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
