#include<stdio.h>
#include<stdlib.h>

typedef struct pq {
    int data;
    struct pq* next;
    int priority;
} pq;

// Max-priority first (higher number = higher priority)
void enqueue(pq** front, pq** rear, int data, int priority) {
    pq *node = (pq*)malloc(sizeof(pq));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->priority = priority;
    node->next = NULL;

    // If queue is empty or new node has highest priority
    if (*front == NULL || priority > (*front)->priority) {
        node->next = *front;
        *front = node;
        if (*rear == NULL) *rear = node;
    } else {
        pq *temp = *front;
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
        if (node->next == NULL) *rear = node;
    }
}

int dequeue(pq** front, pq** rear) {
    if (*front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    pq* temp = *front;
    int val = temp->data;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return val;
}

void display(pq* front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Priority Queue (Highest Priority First):\n");
    while (front != NULL) {
        printf("[%d (P:%d)] ", front->data, front->priority);
        front = front->next;
    }
    printf("\n");
}

int main() {
    pq* front = NULL;
    pq* rear = NULL;
    int choice, data, priority;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(&front, &rear, data, priority);
                break;

            case 2:
                if (front == NULL) {
                    printf("Queue is empty!\n");
                } else {
                    int val = dequeue(&front, &rear);
                    printf("Dequeued value: %d\n", val);
                }
                break;

            case 3:
                display(front);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
