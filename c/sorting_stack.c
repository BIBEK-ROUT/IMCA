#include <stdio.h>
#include <stdlib.h>

int *stack, *temp;
int size;
int top = -1, top1 = -1;

void push(int *stack, int *top, int data) {
    if (*top == size - 1) {
        printf("Stack overflow!!\n");
        return;
    }
    stack[++(*top)] = data;
}

int pop(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack underflow!!\n");
        return -1;
    }
    return stack[(*top)--];
}

int peek(int *stack, int top) {
    if (top == -1) return -1;
    return stack[top];
}

void display(int *stack, int top) {
    if (top == -1) {
        printf("Stack is empty!!\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void sort() {
    while (top != -1) {
        int curr = pop(stack, &top);

        while (top1 != -1 && peek(temp, top1) > curr) {
            push(stack, &top, pop(temp, &top1));
        }

        push(temp, &top1, curr);
    }

    // Move back to original stack (optional)
    while (top1 != -1) {
        push(stack, &top, pop(temp, &top1));
    }
    
    free(temp);
    temp = NULL; // Clear temp pointer to avoid dangling pointer
}
/*
void sort() {
    int curr, i, k;

    for (int j = 0; j <= top; j++) {
        curr = pop(stack, &top);

        if (top1 == -1) {
            push(temp, &top1, curr);
        } else if (peek(temp, top1) < curr) {
            push(temp, &top1, curr);
        } else {
            int count = 0;
            while (top1 != -1 && peek(temp, top1) > curr) {
                push(stack, &top, pop(temp, &top1));
                count++;
            }

            push(temp, &top1, curr);

            while (count--) {
                push(temp, &top1, pop(stack, &top));
            }
        }
    }

    // Move everything back to original stack
    while (top1 != -1) {
        push(stack, &top, pop(temp, &top1));
    }
}
*/
// The above commented sort function is an alternative implementation that can be used.
int main() {
    int data;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    stack = (int *)malloc(size * sizeof(int));
    temp = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        printf("Enter data: ");
        scanf("%d", &data);
        push(stack, &top, data);
    }
/*
    printf("\nOriginal stack:\n");
    display(stack, top);*/

    sort();

    printf("\nSorted stack:\n");
    display(stack, top);

    free(stack);
    return 0;
}
