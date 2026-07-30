#include <stdio.h>
#define max 20
int top = -1;

int peek(char array[], int top) {
    return array[top - 1];
}

int isFull(char array[], int top) {
    if (top == max - 1) return 1;
    else return 0;
}

int isEmpty(char array[], int top) {
    if (top == -1) return 1;
    else return 0;
}


char pop(char array[], int top1) {
    if (top1 <= 0) {
        return -1;
    }
    char temp = array[top1 - 1];
    return temp;
}

int ISP(char c) {
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 2;
    if (c == '*' || c == '/') return 4;
    if (c == '^') return 5;
    if (c != '+' && c != '-' && c != '*' && c != '/' && c != '^') return 8;
    return -1;
}

int ICP(char c) {
    if (c == ')') return 0;
    if (c == '(') return 9;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 3;
    if (c == '^') return 6;
    if (c != '+' && c != '-' && c != '*' && c != '/' && c != '^') return 7;
    return -1;
}

int main() {
    char st[max];
    char item;
    char x;
    int i = 0;

    char str[max] = "(a+b*c-d/e)";

    top = 0;
    st[top] = '(';
    top++;
    i++;

    printf("Infix Expression: %s\n", str);
    printf("Postfix Expression: ");

    while (top > 0) {
        item = str[i];

        x = pop(st, top);
        top--;

        // Case 1: Operands (Letters)
        if (item != '+' && item != '-' && item != '*' && item != '/' && item != '(' && item != ')' && item != '\0') {
            // Restore stack state since we popped x early
            st[top] = x;
            top++;
            printf("%c", item);
            i++;
        }
        // Case 2: Closing parenthesis
        else if (item == ')') {
            while (x != '(') {
                printf("%c", x);
                x = pop(st, top);
                top--;
            }
            i++; // Move past ')'
        }
        // Case 3: Incoming operator has lower/equal priority -> Pop stack
        else if (ISP(x) >= ICP(item)) {
            while (ISP(x) >= ICP(item)) {
                printf("%c", x);
                x = pop(st, top);
                top--;
            }
            st[top] = x;
            top++;
            st[top] = item;
            top++;
            i++;
        }
        // Case 4: Incoming operator has higher priority -> Push to stack
        else if (ISP(x) < ICP(item)) {
            st[top] = x;
            top++;
            st[top] = item;
            top++;
            i++;
        }
        else {
            printf("INVALID EXPRESSION");
        }
    }
    printf("\n");
    return 0;
}