#include <stdio.h>
#include <string.h>

#define MAX 20

int stack[MAX];
int top = -1;

void push(int c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

int peek() {
    if (top >= 0) {
        return stack[top];
    }
    return -1;
}

// In-Stack Priority
int ISP(char c) {
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 2;
    if (c == '*' || c == '/') return 4;
    if (c == '^') return 5;
    return 0;
}

// Incoming Priority
int ICP(char c) {
    if (c == '(') return 9;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 3;
    if (c == '^') return 6;
    return 0;
}

int isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int eval(int x,int y,char s) {
    if (s == '+') {
        return (x+y);
    }
    if (s == '-') {
        return (x-y);
    }
    if (s == '*') {
        return (x*y);
    }
    if (s == '/') {
        return (x/y);
    }
    if (s == '^') {
        return (x^y);
    }
}
int main() {
    char str[MAX] = "(a+(b*c)/d)";
    char post[MAX];
    int i = 0, p = 0;

    printf("Infix Expression: %s\n", str);

    while (str[i] != '\0') {
        char item = str[i];

        // Case 1: Operands
        if (isOperand(item)) {
            post[p++] = item;
            i++;
        }
        // Case 2: Opening Parenthesis
        else if (item == '(') {
            push(item);
            i++;
        }
        // Case 3: Closing Parenthesis
        else if (item == ')') {
            while (top != -1 && peek() != '(') {
                post[p++] = pop();
            }
            pop(); // Remove '(' from stack
            i++;
        }
        // Case 4: Operators
        else {
            while (top != -1 && ISP(peek()) >= ICP(item)) {
                post[p++] = pop();
            }
            push(item);
            i++;
        }
    }

    // Pop remaining elements
    while (top != -1) {
        post[p++] = pop();
    }

    post[p] = '#'; // Null-terminate the string
    post[p+1] = '\0';
    printf("Postfix Expression: %s\n", post);

    //evaluation
    top=-1;
    i=0;
    int x;
    int y;
    char op;
    int t;
    char item=post[i];
    while (item != '#') {
        if (isOperand(item)) {
            printf("\nENTER THE VALUE OF %c : ",item);
            scanf(" %d",&x);
            push(x);
        }
        else {
            op=item;
            y=pop();
            x=pop();
            t = eval(x,y,op);
            push(t);
        }
        i++;
        item=post[i];
    }
    printf("\nVALUE OF FINAL EXPRESSION : %d ",pop());
    return 0;
}