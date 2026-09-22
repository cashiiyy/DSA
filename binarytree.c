#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild; // Fixed: Changed 'node' to 'Node'
    int data;
    struct Node *rchild; // Fixed: Changed 'node' to 'Node'
} Node;

Node* Createnode(int data)
{
    // Fixed: Properly allocated heap memory
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

Node* BuildTree(Node* root, int data)
{
    char dir;
    if (root == NULL)
    {
        return Createnode(data);
    }

    // Fixed: Added space before %c to clear newline characters from input buffer
    printf("ENTER DIRECTION (L/R) : ");
    scanf(" %c", &dir);

    if (dir == 'L' || dir == 'l')
    {
        root->lchild = BuildTree(root->lchild, data);
    }
    else if (dir == 'R' || dir == 'r')
    {
        root->rchild = BuildTree(root->rchild, data);
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
    printf("%d ", root->data); // Fixed: Changed %c to %d for integer data
    PrintTree(root->rchild);
}

int main()
{
    Node* root = NULL; // Fixed: Initialize to NULL so BuildTree can handle root creation cleanly
    char ch;
    int data;

    while (1)
    {
        printf("DO YOU WANT TO ADD DATA TO THE BINARY TREE..?(Y/N): ");
        scanf(" %c", &ch);

        if (ch == 'Y' || ch == 'y')
        {
            printf("ENTER THE DATA : ");
            scanf("%d", &data);
            root = BuildTree(root, data);
        }
        else if (ch == 'N' || ch == 'n')
        {
            break;
        }
        else
        {
            printf("Invalid choice! Please enter Y or N.\n");
        }
    }

    printf("\n----BINARY TREE (In-Order Traversal)----\n");
    PrintTree(root);
    printf("\n");

    return 0;
}
