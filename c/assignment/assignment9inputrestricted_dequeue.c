#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct {
    int arr[SIZE];
    int front, rear;
} InputRestrictedDeque;

void initialize(InputRestrictedDeque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(InputRestrictedDeque *dq) {
    return (dq->rear + 1) % SIZE == dq->front;
}

int isEmpty(InputRestrictedDeque *dq) {
    return dq->front == -1;
}

void insertRear(InputRestrictedDeque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % SIZE;
    }

    dq->arr[dq->rear] = value;
    printf("Inserted at rear: %d\n", value);
}

void deleteFront(InputRestrictedDeque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete.\n");
        return;
    }

    int deleted = dq->arr[dq->front];

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1; // now empty
    } else {
        dq->front = (dq->front + 1) % SIZE;
    }

    printf("Deleted from front: %d\n", deleted);
}

void deleteRear(InputRestrictedDeque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete.\n");
        return;
    }

    int deleted = dq->arr[dq->rear];

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + SIZE) % SIZE;
    }

    printf("Deleted from rear: %d\n", deleted);
}

void display(InputRestrictedDeque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    InputRestrictedDeque dq;
    initialize(&dq);

    int choice, value;
    do {
        printf("\n--- Input Restricted Deque Menu ---\n");
        printf("1. Insert at rear\n");
        printf("2. Delete from front\n");
        printf("3. Delete from rear\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 2:
                deleteFront(&dq);
                break;
            case 3:
                deleteRear(&dq);
                break;
            case 4:
                display(&dq);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
