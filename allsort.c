
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

long long insertionMoves = 0, insertionSwaps = 0;
long long radixMoves = 0, radixSwaps = 0;
long long mergeMoves = 0, mergeSwaps = 0;
long long quickMoves = 0, quickSwaps = 0;

/* Swap two elements and count the swap */
void swap(int *a, int *b, long long *swaps) {
    if (a != b) {
        int temp = *a;
        *a = *b;
        *b = temp;
        (*swaps)++;
    }
}

/* 1. Insertion Sort */
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            insertionMoves++;
            j--;
        }

        a[j + 1] = key;
        insertionMoves++;
    }
}

/* 2. Radix Sort (for non-negative integers) */
int getMax(int a[], int n) {
    int max = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

void countingSort(int a[], int n, int exp) {
    int output[MAX];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = output[i];
        radixMoves++;
    }
}

void radixSort(int a[], int n) {
    int max = getMax(a, n);

    for (int exp = 1; max / exp > 0; ) {
        countingSort(a, n, exp);

        if (exp > max / 10)
            break;

        exp *= 10;
    }
}

/* 3. Merge Sort */
void merge(int a[], int left, int mid, int right) {
    int temp[MAX];
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
        mergeMoves++;
    }

    while (i <= mid) {
        temp[k++] = a[i++];
        mergeMoves++;
    }

    while (j <= right) {
        temp[k++] = a[j++];
        mergeMoves++;
    }

    for (i = left; i <= right; i++) {
        a[i] = temp[i];
        mergeMoves++;
    }
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

/* 4. Quick Sort */
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j], &quickSwaps);
        }
    }

    swap(&a[i + 1], &a[high], &quickSwaps);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

/* Display array */
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int original[MAX], a[MAX], b[MAX], c[MAX], d[MAX];
    int n;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter non-negative integers:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &original[i]) != 1 ||
            original[i] < 0) {
            printf("Invalid input. Use non-negative integers.\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
        a[i] = b[i] = c[i] = d[i] = original[i];

    insertionSort(a, n);
    radixSort(b, n);
    mergeSort(c, 0, n - 1);
    quickSort(d, 0, n - 1);

    printf("\nSorted arrays:\n");

    printf("Insertion Sort: ");
    display(a, n);

    printf("Radix Sort:     ");
    display(b, n);

    printf("Merge Sort:     ");
    display(c, n);

    printf("Quick Sort:     ");
    display(d, n);

    printf("\nOperation comparison:\n");
    printf("%-16s %-10s %-10s\n",
           "Algorithm", "Swaps", "Moves");

    printf("%-16s %-10lld %-10lld\n",
           "Insertion Sort", insertionSwaps, insertionMoves);

    printf("%-16s %-10lld %-10lld\n",
           "Radix Sort", radixSwaps, radixMoves);

    printf("%-16s %-10lld %-10lld\n",
           "Merge Sort", mergeSwaps, mergeMoves);

    printf("%-16s %-10lld %-10lld\n",
           "Quick Sort", quickSwaps, quickMoves);

    return 0;
}