#include <stdio.h>
#include <string.h>
#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    } else {
        printf("Stack overflow!\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow!\n");
        return '\0'; // Return null character if stack is empty
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    // Push all characters to the stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    printf("Reversed string: ");
    // Pop characters to reverse the string
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}
 