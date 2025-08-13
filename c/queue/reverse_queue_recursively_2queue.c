#include <stdio.h>
#include <stdlib.h>

int size;

typedef struct queue {
    int *arr;
    int front, rear;
} queue;

void enqueue(int data, queue *q) {
    if (q->rear == size - 1) {
        printf("Queue overflow!!\n");
        return;
    }
    q->arr[++q->rear] = data;
}

int dequeue(queue *q) {
    if (q->front == size - 1) {
        printf("Queue underflow!!\n");
        return -1;
    } else if (q->front == q->rear) {
        printf("Queue underflow!!\n");
        q->front = -1;
        q->rear = -1;
        exit(1);
    }
    return q->arr[++q->front];
}

void display(queue *q) {
    if (q->rear == -1) {
        printf("Queue is empty!!\n");
        exit(1);
    }
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// ✅ Fixed pointer usage in this function:
void reverseQueue(int n, queue *q, queue *q1) {
    int value;
    if (n == size) {
        enqueue(dequeue(q), q1);
        return;
    }
    value = dequeue(q);
    reverseQueue(n + 1, q, q1);
    enqueue(value, q1);
    return;
}

int main() {
    queue q, q1;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    q.arr = (int *)malloc(sizeof(int) * size);
    if (q.arr == NULL) {
        printf("Memory allocation failed!!\n");
        return 1;
    }
    q.front = -1;
    q.rear = -1;

    q1.arr = (int *)malloc(sizeof(int) * size);
    if (q1.arr == NULL) {
        printf("Memory allocation failed!!\n");
        return 1;
    }
    q1.front = -1;
    q1.rear = -1;

    int data, n1 = 1;
    for (int i = 0; i < size; i++) {
        printf("Enter the data: ");
        scanf("%d", &data);
        enqueue(data, &q);
    }

    reverseQueue(n1, &q, &q1);  // ✅ pointer passed properly now

    printf("The reversed queue is:\n");
    display(&q1);  // ✅ display the reversed one

    free(q.arr);
    free(q1.arr);

    return 0;
}
