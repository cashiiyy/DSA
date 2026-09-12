#include <stdio.h>
struct node
{
    struct node *llink;
    int data;
    struct node *rlink;
};
typedef struct node node;

node *head = NULL;
struct node Createnode()
{
    node *newnode;
    return *newnode;
}
void insert(int data)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->rlink;
    }
    node *node1;
    node1->data=data;
    ptr->rlink=node1;
    node1->llink=ptr;
    node1->rlink=NULL;
}
void display()
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
    }
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    display();
}