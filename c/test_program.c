#include <stdio.h>
#include <string.h>

int isBalanced(char *expr) {
    char stack[100];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[')
            stack[++top] = ch;
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1)
                return 0;

            char last = stack[top--];

            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '['))
                return 0;
        }
    }

    return top == -1; // if stack is empty → valid
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("Balanced \n");
    else
        printf("Not Balanced ❌\n");

    return 0;
}
