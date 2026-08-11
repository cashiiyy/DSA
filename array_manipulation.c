//created for hackerrank array_manipulation(hard)

#include <stdio.h>
#include <stdlib.h>
void print(int arr[],int n) {
    //printing array
    for (int i=1; i <= n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

}
long int max(long long arr[],long int n) {
    long int max1=arr[1];
    for (long int i=1; i <= n; i++) {
        if (arr[i] > max1) {
            max1 = arr[i];
        }
    }
    return max1;
}

int main() {
    long int n,q;
    scanf("%lld %lld",&n,&q);
    long long *arr = (long long *)calloc(n + 2, sizeof(long long));

    long int qr[3][q];

    //reading queries
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lld",&qr[j][i]);
        }
    }

    //printing queries
    // for (int i = 0; i < q; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         printf("%d ",qr[j][i]);
    //     }
    //     printf("\n");
    // }


    //initialising with 0
    for (int i = 1; i <= n; i++) {
        arr[i]=0;
    }

    //using queries to add to array
    //print(arr,n);
    int j=0;
    long int k=0;
    while (j<q) {
        for (k = qr[0][j]; k <= qr[1][j];k++) {
            arr[k]=arr[k]+qr[2][j];

        }
        // print(arr,n);
        j++;
    }
    //print(arr,n);
    printf("%lld",max(arr,n));
    free(arr);
    return 0;
}
