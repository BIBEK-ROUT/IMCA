#include <stdio.h>
#include <stdlib.h>

int *stack;       // pointer for dynamic stack
int size;         // logical size of stack
int top = -1;     // index of top element

// Function to push data into the stack
void push(int data) {
    if (top == size - 1) {
        printf("Stack overflow!!\n");
        return;
    }
    *(stack + (++top)) = data;
}

// Function to pop the top element
void pop() {
    if (top == -1) {
        printf("Stack underflow!!\n");
        return;
    }

    top--;  // logically remove top element

    // Try to shrink the allocated memory
    int *temp = realloc(stack, (top + 1) * sizeof(int));
    if (temp != NULL) {
        stack = temp;
        size = top + 1;
    } else {
        // If realloc fails, keep original stack and warn user
        printf("Warning: Memory reallocation failed. Stack size remains unchanged.\n");
    }
}

// Function to display stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty!!\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", *(stack + i));
    }
    printf("\n");
}

// Main function to run the stack operations
int main() {
    int data;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    stack = (int *)malloc(sizeof(int) * size); // initial memory allocation

    if (stack == NULL) {
        printf("Memory allocation failed!!\n");
        return 1;  // exit with error
    }

    for (int i = 0; i < size; i++) {
        printf("Enter the data you want to enter at position %d: ", i);
        scanf("%d", &data);
        push(data);
    }

    printf("\nPerforming pop operation...\n");
    pop();

    printf("Stack after pop operation:\n");
    display();

    free(stack);  // 🧹 Free the allocated memory
    return 0;
}
