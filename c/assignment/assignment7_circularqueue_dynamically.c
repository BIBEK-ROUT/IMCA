#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front, rear, size, capacity;
} CircularQueue;

// Function to create a queue with initial capacity
CircularQueue* createQueue(int initialCapacity) {
    CircularQueue *q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->capacity = initialCapacity;
    q->data = (int*)malloc(sizeof(int) * q->capacity);
    q->size = 0;
    q->front = 0;
    q->rear = -1;
    return q;
}

// Resize if full
void resizeQueue(CircularQueue *q) {
    int newCapacity = q->capacity * 2;
    int *newData = (int*)malloc(sizeof(int) * newCapacity);

    for (int i = 0; i < q->size; ++i) {
        newData[i] = q->data[(q->front + i) % q->capacity];
    }

    free(q->data);
    q->data = newData;
    q->capacity = newCapacity;
    q->front = 0;
    q->rear = q->size - 1;
    printf("Queue resized to capacity: %d\n", q->capacity);
}

void enqueue(CircularQueue *q, int value) {
    if (q->size == q->capacity) {
        resizeQueue(q);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;
    printf("Enqueued: %d\n", value);
}

int dequeue(CircularQueue *q) {
    if (q->size == 0) {
        printf("Queue underflow!\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    printf("Dequeued: %d\n", value);
    return value;
}

void display(CircularQueue *q) {
    if (q->size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < q->size; ++i) {
        printf("%d ", q->data[(q->front + i) % q->capacity]);
    }
    printf("\n");
}

void freeQueue(CircularQueue *q) {
    free(q->data);
    free(q);
}

int main() {
    int initialCapacity;
    printf("Enter initial capacity of queue: ");
    scanf("%d", &initialCapacity);

    CircularQueue *q = createQueue(initialCapacity);

    int choice, value;
    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    freeQueue(q);
    return 0;
}
