#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
};
void insert_beginning(char data,struct node **head) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->next=*head;
    *head=temp;
}
void insert_end(char data,struct node **head) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->next=NULL;
    struct node *ptr = *head;
    while(ptr->next!=NULL) {
        ptr=ptr->next;
    }
    ptr->next=temp;
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
int main() {
    struct node *head=NULL;
    insert_beginning('A',&head);
    insert_beginning('B',&head);
    insert_end('D',&head);
    // insert_end('d',&head);
    // insert('C','A',head);

    //traversing

    struct node *ptr=head;
    while (ptr!=NULL) {
        printf("%c ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}