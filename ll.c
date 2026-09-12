#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
void insert_beginning(int data,struct node **head) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->next=*head;
    *head=temp;
}
void insert_end(int data,struct node **head) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->next=NULL;
    struct node *ptr = *head;
    if (*head == NULL) {
        *head = temp;
        return;
    }
    else
    {
        while(ptr->next!=NULL) {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void insert(int data,int key,struct node *head) {
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
int main() {
    struct node *head=NULL;
    int n;
    scanf("%d",&n);
    int val;
    while(n!=0)
    {
        if (scanf("%d", &val) == 1) {
            insert_end(val, &head);
        }
        n--;
    }
    struct node *ptr=head;
    while (ptr!=NULL) {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}