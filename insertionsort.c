#include <stdio.h>

void insertionsort(int arr[],int n)
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        k=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>k)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=k;
    }
}

int main()
{
    int arr[] = {7, 8, 5, 3, 9, 1, 2, 10, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionsort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
