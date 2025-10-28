#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 100

char infinix[max], postfix[max];

typedef struct {
    char *arr;
    int top;
} ip;

ip stack;

void push(char data) {
    if (stack.top == max - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack.arr[++stack.top] = data;
}

char pop() {
    if (stack.top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack.arr[stack.top--];
}

int precedency(char symbol) {
    switch (symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isempty() {
    return stack.top == -1;
}

void inf_pre() {
    int i, j = 0;
    char next, symbol;

    for (i = strlen(infinix) - 1; i >= 0; i--) {
        symbol = infinix[i];

        switch (symbol) {
            case ')':
                push(symbol);
                break;

            case '(':
                while (!isempty() && (next = pop()) != ')') {
                    postfix[j++] = next;
                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isempty() && precedency(stack.arr[stack.top]) > precedency(symbol)) {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;

            default:
                if (isalnum(symbol)) {  // Only append valid operands
                    postfix[j++] = symbol;
                }
                break;
        }
    }

    while (!isempty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("displaying the postfix expression: ");
    for(i=0;i<strlen(postfix);i++) {
        printf("%c", postfix[i]);
    }
    printf("Displaying the prefix expression: ");
    for (i = strlen(postfix) - 1; i >= 0; i--) {  // Reverse postfix to get prefix
        printf("%c", postfix[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the infix expression: ");
    fgets(infinix, max, stdin);
    infinix[strcspn(infinix, "\n")] = '\0';  // Remove newline if present

    stack.arr = (char *)malloc(max * sizeof(char));
    stack.top = -1;

    inf_pre();

    free(stack.arr);
    return 0;
}
