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
    if (q->front == size - 1 || q->front == q->rear) {
        printf("Queue underflow!!\n");
        q->front = -1;
        q->rear = -1;
        return -1;
    }
    return q->arr[++q->front];
}

void display(queue *q) {
    if (q->rear == -1 || q->front == q->rear) {
        printf("Queue is empty!!\n");
        return;
    }
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// 🔁 Reverse function – your playground!
void reverseQueue(int n, queue *q,int val) {
    // Implement your recursion here
    int value;
    if(n==size)
    {
        q->rear=-1;
        q->front=-1;
        enqueue(val,q);
        return;
    }
    value=dequeue(q);
    reverseQueue(n+1,q,value);
    enqueue(value,q);
    return;
}

int main() {
    queue q;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    q.arr = (int *)malloc(sizeof(int) * size);
    if (q.arr == NULL) {
        printf("Memory allocation failed!!\n");
        return 1;
    }

    q.front = -1;
    q.rear = -1;

    int data, n1 = 1;
    for (int i = 0; i < size; i++) {
        printf("Enter the data: ");
        scanf("%d", &data);
        enqueue(data, &q);
    }

    printf("\nOriginal Queue:\n");
    display(&q);

    reverseQueue(n1, &q,1);  // Your implementation goes here

    printf("\nReversed Queue:\n");
    display(&q);

    free(q.arr);
    return 0;
}
