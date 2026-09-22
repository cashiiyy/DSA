#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;

Node* Createnode(int data)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;

}

struct Node* BuildTree(Node* root,int data)
{
    char dir;
    if (root == NULL)
    {
        return Createnode(data);
    }
    printf("ENTER DIRECTION (L/R) : ");
    scanf(" %c",&dir);
    if (dir=='L')
    {
        root->lchild = BuildTree(root->lchild,data);
    }
    else if (dir=='R')
    {
        root->rchild = BuildTree(root->rchild,data);
    }
    else
    {
        printf("INVALID CHOICE\n");
    }
    return root;
}
void PrintTree(Node* root)
{
    if (root == NULL)
        return;
    PrintTree(root->lchild);
    printf("%d ",root->data);
    PrintTree(root->rchild);
}

int main()
{
    Node* root=NULL;
    char ch;
    int data;
    root = (Node*)malloc(sizeof(Node));
    root->lchild = NULL;
    root->rchild = NULL;
    while (1)
    {
        printf("DO YOU WANT TO ADD DATA TO THE BINARY TREE..?(Y/N)\n");
        scanf(" %c",&ch);
        if (ch == 'Y' || ch == 'y')
        {
            printf("ENTER THE DATA : ");
            scanf("%d",&data);
            root = BuildTree(root,data);
        }
        else if (ch == 'N' || ch == 'n')
        {
            break;
        }
        else
        {
            printf("INVALID CHOICE\n");
        }
        printf("\n");
    }
    printf("\n----BINARY TREE----\n\n");
    PrintTree(root);
    return 0;
}