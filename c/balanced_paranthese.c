#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stack;
int size;
int top = -1;

void push(char data)
{
    if (top == size - 1) {
        printf("Stack overflow!!\n");
        return;
    }
    stack[++top] = data;
}

int check()
{
    if (top == -1) {
        printf("Stack is empty!!\n");
        return 0;
    }

    char *req = (char *)malloc(size * sizeof(char));
    int count = -1;

    for (int i = 0; i <= top; i++) {
        char ch = stack[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            req[++count] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (count == -1) {
                free(req);
                return 0;  // closing without opening
            }
            char last = req[count--];
            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                free(req);
                return 0;  // mismatch
            }
        }
    }

    int balanced = (count == -1);
    free(req);
    return balanced;
}

int main()
{
    char input[100];
    printf("Enter the full parentheses expression (e.g. (){}[]): ");
    scanf("%s", input);

    size = strlen(input);
    stack = (char *)malloc(size * sizeof(char));

    for (int i = 0; i < size; i++) {
        push(input[i]);
    }

    if (check())
        printf("Balanced \n");
    else
        printf("Not Balanced \n");

    free(stack);
    return 0;
}
