 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int data) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

void evaluate(char postfix[]) {
    char *token = strtok(postfix, " ");
    int a, b, result;

    while (token != NULL) {
        if (isdigit(token[0])) {
            // If it's a number, convert to int and push
            push(atoi(token));
        }
        else {
            // It's an operator
            b = pop();
            a = pop();

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Division by zero!\n");
                        exit(1);
                    }
                    result = a / b;
                    break;
                default:
                    printf("Unknown operator: %s\n", token);
                    exit(1);
            }
            push(result);
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression (space between everything, e.g., 12 3 +):\n");
    fgets(postfix, MAX, stdin);

    // Remove newline character if present
    postfix[strcspn(postfix, "\n")] = '\0';

    evaluate(postfix);

    if (top == 0) {
        printf("Result = %d\n", stack[top]);
    } else {
        printf("Invalid expression. Stack has %d elements left.\n", top + 1);
    }

    return 0;
}
