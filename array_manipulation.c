#include <stdio.h>

void print(int arr[],int n) {
    //printing array
    printf("[");
    for (int i=1; i <= n; i++) {
        printf("%d ",arr[i]);
    }
    printf("]");
    printf("\n");

}
int max(int arr[],int n) {
    int max1=arr[1];
    for (int i=1; i <= n; i++) {
        if (arr[i] > max1) {
            max1 = arr[i];
        }
    }
    return max1;
}

int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    int arr[n+1];

    int qr[3][q];

    printf("Enter number of elements in array\n");
    //reading queries
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d",&qr[j][i]);
        }
    }

    //printing queries
    for (int i = 0; i < q; i++) {
        printf("[");
        for (int j = 0; j < 3; j++) {
            printf("%d ,",qr[j][i]);
        }
        printf("]");
        printf("\n");
    }

    printf("\n");

    //initialising with 0
    for (int i = 1; i <= n; i++) {
        arr[i]=0;
    }

    //using queries to add to array
    print(arr,n);
    int j=0;
    int k=0;
    while (j<q) {
        for (k = qr[0][j]; k <= qr[1][j];k++) {
            arr[k]=arr[k]+qr[2][j];

        }
        print(arr,n);
        j++;
    }
    printf("\nFINAL\n");
    print(arr,n);
    printf("\n");
    printf("%d\n",max(arr,n));
    return 0;
}