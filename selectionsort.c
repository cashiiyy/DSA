#include <stdio.h>

void selectionSort(int a[], int n)
{
    int min_index,temp;
    for (int i = 0; i < n-1; i++)
    {
        min_index = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
    }
}

int main()
{
    int arr[] = {7, 8, 5, 3, 9, 1, 2, 10, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
