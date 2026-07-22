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
    char temp=array[top1];
    return temp;
}
int ISP(char c) {
    if (c=='+' || c=='-') {
        return 2;
    }
    if (c=='*' || c=='/') {
        return 4;
    }
    if (c=='^') {
        return 5;
    }
    if (c!='+' || c!='-' || c!='*' || c!='/' || c!='^') {
        return 8;
    }
    if (c=='(') {
        return 0;
    }
}
int ICP(char c) {
    if (c=='+' || c=='-') {
        return 1;
    }
    if (c=='*' || c=='/') {
        return 3;
    }
    if (c=='^') {
        return 6;
    }
    if (c!='+' || c!='-' || c!='*' || c!='/' || c!='^') {
        return 7;
    }
    if (c=='(') {
        return 9;
    }
    if (c==')') {
        return 0;
    }
}



int main() {
    char st[max];
    char item;
    int i=0;
    char str[max]="a+b*c-d/e)";
    top=0;
    item=pop(st,top);
    st[top]=item;
    top++;
    while (top>0) {
        item=str[i];
        i++;
        char x;
        x=pop(st,top);
        // printf("%c",x);
        if (item != '+' || item != '-' || item != '*' || item != '/') {
            st[top]=item;
            top++;
            printf("%c",st[top]);
            i++;
        }
        if (item==')') {
            while (x!='(') {
                printf("%c",x);
                x=pop(st,top);
                top--;
            }
        }
        else if (ISP(x)>=ICP(item)) {
            while (ISP(x)>=ICP(item)) {
                printf("%c",x);
                x=pop(st,top);
                top--;
            }
            st[top]=x;
            top++;
            st[top]=item;
            top++;
            i++;
        }
        else if (ISP(x)<ICP(item)) {
            st[top]=x;
            top++;
            st[top]=item;
            top++;
            i++;
        }
        else {
            printf("INVALID EXPRESSION");
        }
        }
}