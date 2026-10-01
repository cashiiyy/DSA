#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* lchild;
    int data;
    struct Node* rchild;
} Node;

static Node* CreateNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    temp->data = data;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

static Node* BuildTree(Node* root, int data)
{
    if (root == NULL)
    {
        return CreateNode(data);
    }

    char dir;
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

static void Print_IO(Node* root)
{
    if (root == NULL)
        return;

    Print_IO(root->lchild);
    printf("%d ", root->data);
    Print_IO(root->rchild);
}

static void Print_PostO(Node* root)
{
    if (root == NULL)
        return;

    Print_PostO(root->lchild);
    Print_PostO(root->rchild);
    printf("%d ", root->data);
}

static void Print_PreO(Node* root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    Print_PreO(root->lchild);
    Print_PreO(root->rchild);
}

static Node* insert(Node* root, int item)
{
    if (root == NULL)
    {
        return CreateNode(item);
    }

    if (item < root->data)
    {
        root->lchild = insert(root->lchild, item);
    }
    else if (item > root->data)
    {
        root->rchild = insert(root->rchild, item);
    }
    else
    {
        printf("\nITEM ALREADY EXISTS : %d\n", item);
    }

    return root;
}

Node* delete_node(Node* root, int item)
{
    // Base Case: Not found
    if (root == NULL)
    {
        printf("\nITEM %d DOESN'T EXIST\n", item);
        return root;
    }

    // Traverse left
    if (item < root->data)
    {
        root->lchild = delete_node(root->lchild, item);
    }
    // Traverse right
    else if (item > root->data)
    {
        root->rchild = delete_node(root->rchild, item);
    }
    // Found the target node
    else
    {
        // Case 1 & 2: Node has one child or no child
        if (root->lchild == NULL)
        {
            Node* temp = root->rchild;
            free(root); // PREVENT MEMORY LEAK!
            return temp;
        }
        else if (root->rchild == NULL)
        {
            Node* temp = root->lchild;
            free(root);
            return temp;
        }

        // Case 3: Node has two children.
        // Get the inorder successor (smallest element in the Right Subtree)
        Node* temp = root->rchild;
        while (temp->lchild != NULL) {
            temp = temp->lchild;
        }

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Recursively delete the inorder successor in the right subtree
        root->rchild = delete_node(root->rchild, temp->data);
    }
    return root;
}


int main(void)
{
    Node* root = NULL;
    int arr[] = {56, 15, 45, 22, 10, 5, 60, 80, 78, 15, -1};
    int i = 0;

    while (arr[i] != -1)
    {
        root = insert(root, arr[i]);
        i++;
    }


    printf("\n----BINARY TREE (In-Order Traversal)----\n");
    Print_IO(root);
    printf("\n----BINARY TREE (Post-Order Traversal)----\n");
    Print_PostO(root);
    printf("\n----BINARY TREE (Pre-Order Traversal)----\n");
    Print_PreO(root);
    printf("\n");

    delete_node(root,45);

    printf("\n----BINARY TREE (In-Order Traversal)----\n");
    Print_IO(root);
    printf("\n----BINARY TREE (Post-Order Traversal)----\n");
    Print_PostO(root);
    printf("\n----BINARY TREE (Pre-Order Traversal)----\n");
    Print_PreO(root);
    printf("\n");

    return 0;
}
