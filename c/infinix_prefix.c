#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct stack 
{
    char arr[MAX];
    int top;
} stack;

void initstack(stack *st) 
{
    st->top = -1;
}

int isempty(stack *st) 
{
    return st->top == -1;
}

void push(stack *st, char ch) {
    if (st->top == MAX - 1) {
        printf("\nStack overflow");
        exit(1);
    }
    st->arr[++(st->top)] = ch;
}

char pop(stack *st) {
    if (isempty(st)) {
        printf("\nStack underflow");
        exit(1);
    }
    return st->arr[(st->top)--];
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

int main() {
    char s[MAX], post[MAX];
    int i = 0, j = 0;

    stack st1;
    initstack(&st1);

    printf("Enter the infix expression: ");
    fgets(s, sizeof(s), stdin);

    if (s[strlen(s) - 1] == '\n') {
        s[strlen(s) - 1] = '\0'; // remove newline
    }

    push(&st1, ')');                  // Push ')' to the stack
    /*if (s[strlen(s)] == '\0') 
    {
        s[strlen(s)+1] = ')';
    }
    if (s[strlen(s)] == '\0') 
    {
        s[strlen(s)+1] = '(';
    }*/
    i=strlen(s)-1;
    while (i != -1) {
        if (isalpha(s[i]) || isdigit(s[i])) {
            post[j++] = s[i];
        } 
        else if (s[i] == ')') 
        {
            push(&st1, s[i]);
        } 
        else if (s[i] == '(') 
        {
            while (st1.arr[st1.top] != ')') 
            {
                post[j++] = pop(&st1);
            }
            pop(&st1); // Remove '(' from stack
        } 
        else 
        {
            while (!isempty(&st1) && precedence(st1.arr[st1.top]) > precedence(s[i])) 
            {
                post[j++] = pop(&st1);
            }
            push(&st1, s[i]);
        }
        i--;
    }
    for(i=st1.top;st1.arr[i]!=')';i--)
    {
        post[j++]=pop(&st1);
    }

    post[j] = '\0';
    printf("Prefix Expression: ");
    for(i=strlen(post)-1;i>=0;i--)
    printf("%c", post[i]);
    return 0;
}