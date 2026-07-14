#include <stdio.h>
#define max 15
int peek(char array[],int top) {
    return array[top];
}
int isFull(char array[],int top) {
    if (top==max) {
        return 1;
    }
    else {
        return 0;
    }
}
int isEmpty(char array[],int top) {
    if (top==-1) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    char st[max];
    int top=-1;
    char string[max]="(a+b)*(b)*c";
    int l=0;
    while (string[l]!='\0') {
        if (string[l]=='(') {
            top++;
            st[top]=string[l];
            l++;
        }
        else if (string[l]==')') {
            st[top]=0;
            top--;
            l++;
        }
        else {
            l++;
        }
    }
    if (top==-1) {
        printf("PARENTHESIS MATCHED");

    }
    else {
        printf("PARENTHESIS NOT MATCHED");
    }

    return 0;
}