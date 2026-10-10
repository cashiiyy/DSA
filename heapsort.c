#include <stdio.h>
#include <math.h>

// Fixed: Use pointers to swap actual array items in memory
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    // Fixed: Verify child index is inside heap limits, then compare array values
    if (l < n && a[l] > a[largest])
    {
        largest = l; // Store the index, not the value
    }

    if (r < n && a[r] > a[largest])
    {
        largest = r; // Store the index, not the value
    }

    // If the largest is not the root node
    if (largest != i)
    {
        swap(&a[i], &a[largest]); // Pass memory addresses

        // Fixed: Recursively heapify the affected subtree downwards
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    // Build max-heap
    for (int i = floor(n / 2) - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i >= 1; i--)
    {
        swap(&a[0], &a[i]); // Move current max element to the end
        heapify(a, i, 0);   // Restore heap property on reduced heap
    }
}

int main()
{
    int arr[] = {7, 8, 5, 3, 9, 1, 2, 10, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
