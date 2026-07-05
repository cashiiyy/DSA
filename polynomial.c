#include <stdio.h>
#define max 10
struct polynomial {
    int coef[max];
    int degree[max];
};
void printpolynomial(struct polynomial poly,int n){
    printf("The polynomial is : \t");
    for (int i=0;i<n;i++) {
        printf(" %dx^%d ",poly.coef[i],poly.degree[i]);
        if (i<n-1){
            printf("+");
        }
        
    }
    printf("\n");

}
int search(int element,int n,int array[]) {
    int l=0;
    for (int i=0;i<n;i++) {
        if (array[i]==element) {
            l=i;
        }
    }
    if (l==0) {
        return 0;
    }
    else {
        return l;
    }

}

void sum(struct polynomial poly1,int n,struct polynomial poly2,int m,struct polynomial poly3) {
    for (int i=0;i<n;i++) {
        if ((search(poly1.degree[i],m,poly2.degree))!=0) {
            poly3.coef[i]=poly1.coef[i]+poly2.coef[search(poly1.degree[i],n,poly2.degree)];
        }
        else {
            poly3.coef[i]=poly1.coef[i];
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

    printpolynomial(poly1,n);
    printpolynomial(poly2,m);

    // sum(poly1,n,poly2,m,poly3);
    // printpolynomial(poly3,n);
    return 0;
}
