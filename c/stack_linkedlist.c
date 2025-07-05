#include<stdio.h>
#include<stdlib.h>

typedef struct stack_list {
    int data;
    struct stack_list *next;
} stl;

void push(stl **head, int data) {
    stl *node = (stl *)malloc(sizeof(stl));
    if (node == NULL) {
        printf("Memory allocation failed!!");
        exit(1);
    }
    node->data = data;
    node->next = *head;
    *head = node;
}

void pop(stl **head) {
    if (*head == NULL) {
        printf("Stack underflow!!\n");
        return;
    }
    stl *temp = *head;
    *head = temp->next;
    free(temp);
}

void peek(stl *head) {
    if (head == NULL) {
        printf("Stack is empty!!\n");
        return;
    }
    printf("Top element is: %d\n", head->data);
}

void display(stl *head) {
    if (head == NULL) {
        printf("Stack is empty!!\n");
        return;
    }
    printf("Stack elements top to bottom: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int data;
    stl *head = NULL;  // Important init!
    char ch;

    printf("If you want to create a stack press y: ");
    scanf(" %c", &ch);

    while (ch == 'y') {
        printf("Please enter the data: ");
        scanf(" %d", &data);
        push(&head, data);
        printf("Press y if you want to insert again: ");
        scanf(" %c", &ch);
    }

    printf("\nThe elements are:\n");
    display(head);

    peek(head);

    printf("\nAfter popping one element:\n");
    pop(&head);
    display(head);

    peek(head);

    return 0;
}
