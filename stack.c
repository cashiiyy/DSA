#include <stdio.h>
#define max 20
int top = -1;
int peek(char array[],int top) {
    return array[top];
}
int isFull(char array[],int top) {
    if (top==max-1) {
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
char pop(char array[],int top1) {
    if (top1==-1) {
        return -1;
    }
    else {

        char temp=array[top1];
        top1--;
        return temp;
    }
}
int main() {
    char st[max];
    char string[max]="(a+b+{c*d}-[c/f]*c)";
    int l=0;
    while (string[l]!='\0') {
        if (string[l]=='(' || string[l]=='{' || string[l]=='[') {
            top++;
            st[top]=string[l];
            l++;
        }
        else if (string[l]==')' || string[l]=='}' || string[l]==']') {
            if (isEmpty(st,top)) {
                top=1;
                break;
            }
            char temp = st[top];
            if (string[l]==')' && temp=='('||
                string[l]=='}' && temp=='{'||
                string[l]==']' && temp=='[') {

                printf("popped : %c \n",string[l]);
                top--;
                l++;
            }
            else {
                break;
            }
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