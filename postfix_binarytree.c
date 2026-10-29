
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct Node {
    char data;
    struct Node *left, *right;
};

char operators[MAX];
int top = -1;

struct Node *stack[MAX];
int nodeTop = -1;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' || ch == '^';
}

struct Node *createNode(char ch) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = ch;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Convert infix expression to postfix */
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isspace((unsigned char)ch))
            continue;

        if (isalnum((unsigned char)ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            operators[++top] = ch;
        }
        else if (ch == ')') {
            while (top >= 0 && operators[top] != '(')
                postfix[k++] = operators[top--];

            if (top >= 0)
                top--;
        }
        else if (isOperator(ch)) {
            while (top >= 0 && operators[top] != '(' &&
                   (precedence(operators[top]) > precedence(ch) ||
                   (precedence(operators[top]) == precedence(ch)
                    && ch != '^'))) {
                postfix[k++] = operators[top--];
            }

            operators[++top] = ch;
        }
    }

    while (top >= 0)
        postfix[k++] = operators[top--];

    postfix[k] = '\0';
}

/* Build expression tree from postfix */
struct Node *buildTree(char postfix[]) {
    nodeTop = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        struct Node *newNode = createNode(ch);

        if (isOperator(ch)) {
            newNode->right = stack[nodeTop--];
            newNode->left = stack[nodeTop--];
        }

        stack[++nodeTop] = newNode;
    }

    return stack[nodeTop];
}

/* Prefix: Root, Left, Right */
void prefix(struct Node *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        prefix(root->left);
        prefix(root->right);
    }
}

/* Postfix: Left, Right, Root */
void postfix(struct Node *root) {
    if (root != NULL) {
        postfix(root->left);
        postfix(root->right);
        printf("%c ", root->data);
    }
}

int main(void) {
    char infix[MAX], post[MAX];

    printf("Enter an arithmetic expression: ");
    if (fgets(infix, sizeof(infix), stdin) == NULL)
        return 1;

    infixToPostfix(infix, post);

    struct Node *root = buildTree(post);

    printf("\nPostfix expression: %s\n", post);

    printf("Prefix expression:  ");
    prefix(root);

    printf("\nPostfix traversal:  ");
    postfix(root);

    printf("\n");
    return 0;
}
