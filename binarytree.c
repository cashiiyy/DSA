#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild; // Fixed: Changed 'node' to 'Node'
    char data;
    struct Node *rchild; // Fixed: Changed 'node' to 'Node'
} Node;

Node* Createnode(char data)
{
    // Properly allocated heap memory
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

Node* BuildTree(Node* root, char data)
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
        // Adds to Left Child of current root
        root->lchild = BuildTree(root->lchild, data);
    }
    else if (dir == 'R' || dir == 'r')
    {
        // Adds to Right Child of current root
        root->rchild = BuildTree(root->rchild, data);
    }
    else
    {
        printf("INVALID CHOICE\n");
    }
    return root;
}

void Print_IO(Node* root)//IN_order
{
    if (root == NULL)
        return;
    Print_IO(root->lchild);//left
    printf("%c ", root->data);//root
    Print_IO(root->rchild);//right
}

void Print_PostO(Node* root)
{
    if (root == NULL)
        return;
    Print_PostO(root->lchild);//left
    Print_PostO(root->rchild);//right
    printf("%c ", root->data);//root
}

void Print_PreO(Node* root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);//root
    Print_PreO(root->lchild);//left
    Print_PreO(root->rchild);//right
}

int main()
{
    Node* root = NULL; // Fixed: Initialize to NULL so BuildTree can handle root creation cleanly
    char ch;
    // FIX: Changed 'int data' to 'char data' to match Node structure
    char data;

    while (1)
    {
        printf("DO YOU WANT TO ADD DATA TO THE BINARY TREE..?(Y/N): ");
        scanf(" %c", &ch);

        if (ch == 'Y' || ch == 'y')
        {
            printf("ENTER THE DATA : ");
            scanf(" %c", &data);
            // This call properly adds a node to the left (L) or right (R) of the current root's children
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
    Print_IO(root);
    printf("\n----BINARY TREE (Post-Order Traversal)----\n");
    Print_PostO(root);
    printf("\n----BINARY TREE (Pre-Order Traversal)----\n");
    Print_PreO(root);
    printf("\n");

    return 0;
}
