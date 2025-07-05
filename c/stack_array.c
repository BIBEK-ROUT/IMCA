#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TOP -1

typedef struct {
    int top;
    int size;
    int *ptr;
} stack;

//  Initializes the stack (sets top, size, and allocates memory)
void createStack(stack *s, int size) {
    s->top = DEFAULT_TOP;
    s->size = size;
    s->ptr = (int *)malloc(size * sizeof(int));
    if (s->ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

//  Push using pointers only
void push(stack *s, int data) {
    if (s->top == s->size - 1) {
        printf("Stack overflow!!\n");
        return;
    }
    *(s->ptr + (++(s->top))) = data;
}

//  Display using pointers only
void display(stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!!\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", *(s->ptr + i));
    }
    printf("\n");
}

//  Pop using pointers (optional feature!)
int pop(stack *s) {
    if (s->top == -1) {
        printf("Stack underflow!!\n");
        return -1;
    }
    return *(s->ptr + (s->top--));
}

int main() {
    stack s;
    int size, data;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    createStack(&s, size);  // no need to set top manually

    for (int i = 0; i < s.size; i++) {
        printf("Enter data for position %d: ", i + 1);
        scanf("%d", &data);
        push(&s, data);
    }

    display(&s);

    // Optional: Try popping one item
    printf("Popping top item: %d\n", pop(&s));
    display(&s);

    free(s.ptr);  //  Don't forget to free memory!

    return 0;
}
