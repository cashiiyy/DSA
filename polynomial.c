#include <stdio.h>
#define max 10
struct polynomial {
    int coef[max];
    int degree[max];
};

void printpolynomial(struct polynomial poly,int n){
    printf("The polynomial is : \t");
    for (int i=0;i<n;i++) {
        if (poly.coef[i]!=0) {
            printf(" %dx^%d ",poly.coef[i],poly.degree[i]);
        if (i<n-1){
            printf("+");
        }

        }

        
    }
    printf("\n");

}

int search(int element,int n,int array[]) {
    int l=-1;
    for (int i=0;i<n;i++) {
        if (array[i]==element) {
            l=i;
        }
    }
    if (l>=0) {
        return l;
    }
    else {
        return -1;
    }

}

void sort(struct polynomial poly,int n) {
    int temp1,temp2;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (poly.degree[j]<poly.degree[j+1]) {

                temp1=poly.degree[j];
                temp2=poly.coef[j];

                poly.degree[j]=poly.degree[j+1];
                poly.coef[j]=poly.coef[j+1];

                poly.degree[j+1]=temp1;
                poly.coef[j+1]=temp2;
            }
        }

    }

}

int main() {
    struct polynomial poly1,poly2,poly3;

    //read1
    int n;
    printf("Enter the no: of terms : ");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        printf("Enter degree  %d : ",i+1);
        scanf("%d",&poly1.degree[i]);
    }
    printf("\nCOEFFICIENTS\n");
    for (int i=0;i<n;i++) {
        printf("Enter the coefficient of x^%d: ",poly1.degree[i]);
        scanf("%d",&poly1.coef[i]);
    }

    //read2
    int m;
    printf("Enter the no: of terms : ");
    scanf("%d",&m);
    for (int i=0;i<m;i++) {
        printf("Enter degree  %d : ",i+1);
        scanf("%d",&poly2.degree[i]);
    }
    printf("\nCOEFFICIENTS\n");
    for (int i=0;i<m;i++) {
        printf("Enter the coefficient of x^%d: ",poly2.degree[i]);
        scanf("%d",&poly2.coef[i]);
    }

    //initializing with poly3 with zero
    for (int i=0;i<n+m;i++) {
        poly3.degree[i]=0;
        poly3.coef[i]=0;
    }


    printpolynomial(poly1,n);
    printpolynomial(poly2,m);

    //sum
    for (int i=0;i<n;i++) {
        if ((search((poly1.degree[i]),m,poly2.degree))>=0) {
            int l = search((poly1.degree[i]),m,poly2.degree);
            poly3.degree[i]=poly1.degree[i];
            poly3.coef[i]=poly1.coef[i]+poly2.coef[l];
            poly2.degree[l]=0;
            poly2.coef[l]=0;
        }
        else {
            poly3.coef[i]=poly1.coef[i];
            poly3.degree[i]=poly1.degree[i];
        }
    }
    int k=n;
    for (int i=0;i<m;i++) {
        {
            if (poly2.degree[i]!=0) {
                    {
                        for (int j=k;j<max;j++) {
                            poly3.degree[j]=poly2.degree[i];
                            poly3.coef[j]=poly2.coef[i];
                            k++;
                            break;
                        }

                    }

            }
        }
    }

    sort(poly3,n+m);
    printpolynomial(poly3,n+m);
    return 0;
}