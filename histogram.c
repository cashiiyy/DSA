#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int arr[n];

    //reading
    printf("Enter %d numbers: ",n);
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }

    //interval
    printf("Enter the interval you want to find the frequency of : ");
    int inter1;
    scanf("%d",&inter1);
    int inter2 = inter1;
    //maximum element
    int max=arr[0];
    for (int i=1;i<n;i++) {
        if (arr[i]>max) {
            max=arr[i];
        }
    }
    printf("\nMaximum element : %d\n",max);
    if (max%inter1!=0) {
        max=max+inter1;
    }

    int j=1;
    while (inter1<=max) {
        int count = 0;
        for (int i=0;i<n;i++) {
            if (arr[i]<=inter1 && arr[i]>(inter1-inter2)) {
                count++;
            }

        }
        j=j+1;
        printf("\n(%d-%d) : %d\n",inter1-inter2,inter1,count);
        inter1=(inter2*j);
    }
    return 0;
}
