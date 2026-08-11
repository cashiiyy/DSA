#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node *next;
};
/*
void insert_beginning(char data,struct node **head) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->next=*head;
    *head=temp;
}
void insert(char data,char key,struct node *head) {

    struct node *ptr = head;
    while (ptr->next!=NULL) {
        if (ptr->data == key) {
            struct node *temp = (struct node *) malloc(sizeof(struct node));
            temp->data = data;
            temp->next = ptr->next;
            ptr->next = temp;
            break;
        }
        else {
            ptr=ptr->next;
        }
    }
}
*/
void insert_end(int coef,int exp,struct node **head) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next=NULL;
    struct node *ptr = *head;
    if (*head == NULL) {
        *head = temp;
        return;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
void read(struct node **head,int n) {
    int i=0;
    while (i<n) {
        int coef,exp;
        printf("\nEnter the coefficient and exponent :");
        scanf("%d %d", &coef,&exp);
        insert_end(coef,exp,head);
        i++;
    }
}
void print(struct node **head) {
    int i=0;
    struct node *ptr=*head;
    printf("The polynomial is : \t");
    while (ptr != NULL) {
        if (ptr->coef!=0) {
            printf(" %dx^%d +",ptr->coef,ptr->exp);
        }
        ptr=ptr->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms :\t");
    scanf("%d", &n);
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *poly3 = NULL;



    //poly1
    read(&poly1,n);
    printf("\n----------------POLYNOMIAL 1-----------------\n");
    print(&poly1);

    //poly2
    int m;
    printf("Enter the number of terms :\t");
    scanf("%d", &m);
    read(&poly2,m);
    printf("\n----------------POLYNOMIAL 2-----------------\n");
    print(&poly2);

    //sum
    struct node *i = poly1;
    struct node *j = poly2;

    while (i!=NULL && j!=NULL ) {
        if (i->exp==j->exp) {
            insert_end(((i->coef)+(j->coef)),(i->exp),(&poly3));
            i=i->next;
            j=j->next;
        }
        else if (i->exp>j->exp) {
            insert_end(i->coef,i->exp,&poly3);
            i=i->next;
        }
        else if (j->exp>i->exp) {
            insert_end(j->coef,j->exp,&poly3);
            j=j->next;
        }
    }
    //appending1
    while (i!=NULL) {
        insert_end(i->coef,i->exp,&poly3);
        i=i->next;
    }
    //appending2
    while(j!=NULL) {
        insert_end(j->coef,j->exp,&poly3);
        j=j->next;
    }


    printf("\n----------------POLYNOMIAL 3-----------------\n");
    print(&poly3);

    poly1 = NULL;
    poly2 = NULL;
    poly3 =NULL;
    return 0;
}