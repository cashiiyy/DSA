#include <stdio.h>
#define max 20 // Increased max size to accommodate sums

typedef struct {
    int row;
    int col;
    int val;
} terms;

void read(terms a[]) {
    printf("Enter total no: of rows and columns : ");
    scanf("%d %d", &a[0].row, &a[0].col);
    printf("Enter number of non-zero terms : ");
    scanf("%d", &a[0].val);
    for(int i = 1; i <= a[0].val; i++) {
        printf("Enter the row, column, value: ");
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);
    }
}

void print(terms a[]) {
    printf("Rows: %d, Cols: %d, Total Terms: %d\n", a[0].row, a[0].col, a[0].val);
    for (int i = 1; i <= a[0].val; i++) {
        printf("[%d , %d , %d]\n", a[i].row, a[i].col, a[i].val);
    }
}

void transpose(terms a[],terms b[]) {
    int n,i,j;
    n=a[0].val;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=n;
    for (i=1;i<=n;i++) {
        b[i].row=a[i].col;
        b[i].col=a[i].row;
        b[i].val=a[i].val;
    }

}

void sum(terms a[], terms b[], terms result[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("Error: Matrix dimensions do not match!\n");
        result[0].val = 0;
        return;
    }

    result[0].row = a[0].row;
    result[0].col = a[0].col;

    int i = 1, j = 1, k = 1;

    // Traverse both matrices simultaneously
    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            // Element in A comes first
            result[k++] = a[i++];
        }
        else if (a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)) {
            // Element in B comes first
            result[k++] = b[j++];
        }
        else {
            // Row and column match: add values
            int total_val = a[i].val + b[j].val;
            if (total_val != 0) { // Only store non-zero sums
                result[k].row = a[i].row;
                result[k].col = a[i].col;
                result[k].val = total_val;
                k++;
            }
            i++;
            j++;
        }
    }

    // Copy remaining elements of A
    while (i <= a[0].val) {
        result[k++] = a[i++];
    }

    // Copy remaining elements of B
    while (j <= b[0].val) {
        result[k++] = b[j++];
    }

    // Set total number of terms in the result matrix
    result[0].val = k - 1;
}

int main() {
    terms term1[max];
    terms term2[max];
    terms sum_terms[max];

    printf("--- Matrix 1 ---\n");
    read(term1);

    printf("--- Matrix 2 ---\n");
    read(term2);

    sum(term1, term2, sum_terms);

    printf("\n--- Resulting Sum Matrix ---\n\n");
    print(sum_terms);

    return 0;
}
