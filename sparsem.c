#include <stdio.h>
#define max 10

typedef struct {
    int row;
    int col;
    int val;
} terms;

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

void read(terms a[]) {

    printf("Enter number of terms : ");
    scanf("%d",&a[0].val);
    printf("Enter total no: of rows and columns : ");
    scanf("%d %d",&a[0].row,&a[0].col);
    for(int i=1;i<=a[0].val;i++) {
        printf("Enter the row, column,value : ");
        scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].val);
    }

}

void print(terms a[]) {
    for (int i=0;i<=a[0].val;i++) {
        printf("[%d , %d , %d]\n",a[i].row,a[i].col,a[i].val);
    }
}

int main() {


    terms term1[max];
    terms term2[max];
    terms sum[max];
    // terms trans[max];
    read(term1);
    print(term1);
    read(term2);
    print(term2);

    //sum
    sum[0].row=term1[0].row;
    sum[0].col=term1[0].col;

    for (int i=1;i<=term1[0].val;i++) {
        if (term1[i].row == term2[0].row && term1[i].col == term2[0].col) {
            sum[i].row=term1[i].row;
            sum[i].col=term1[i].col;
            sum[i].val=term1[i].val+term2[i].val;
            term2[i].val=0;
        }
        else {
            sum[i].row=term1[i].row;
            sum[i].col=term1[i].col;
            sum[i].val=term1[i].val;
        }

    }
    int currentB=term1[0].val+1;
    printf("\n%d\n",currentB);
    for (int i=0;i<=term2[0].val;i++) {
        if (term2[i].val!=0) {
            sum[currentB].row=term2[i].row;
            sum[currentB].col=term2[i].col;
            sum[currentB].val=term2[i].val;
            currentB;
        }
    }

    print(sum);

}