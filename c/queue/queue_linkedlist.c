#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list queue
typedef struct qll {
    int data;
    struct qll *next;
} qll;

// Function to insert (enqueue) an element at the rear of the queue
void enqueue(int data, qll **front, qll **rear) {
    qll *node = (qll *)malloc(sizeof(qll));
    if (node == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }

    node->data = data;
    node->next = NULL;

    // If queue is empty, both front and rear point to new node
    if (*front == NULL) {
        *front = *rear = node;
    } else {
        // Add new node at the end and update rear
        (*rear)->next = node;
        *rear = node;
    }
}

// Function to remove (dequeue) the front element
void dequeue(qll **front, qll **rear) {
    if (*front == NULL) {
        printf("Queue underflow!!\n");
        return;
    }

    qll *temp = *front;

    // If only one element was present
    if (*front == *rear) {
        *front = *rear = NULL;
    } else {
        *front = (*front)->next;
    }

    free(temp);
}

// Function to display the queue elements from front to rear
void display(qll *front) {
    if (front == NULL) {
        printf("Queue is empty!!\n");
        return;
    }

    printf("Queue elements: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

// Main function to drive the queue
int main() {
    qll *front = NULL, *rear = NULL;  // Initialize front and rear to NULL
    int data;
    char ch;

    printf("If you want to create a dynamic queue press 'y': ");
    scanf(" %c", &ch);

    while (ch == 'y') {
        printf("Enter the data: ");
        scanf("%d", &data);
        enqueue(data, &front, &rear);

        printf("If you want to insert again press 'y': ");
        scanf(" %c", &ch);
    }

    // Display the queue
    printf("\nDisplaying the queue elements:\n");
    display(front);

    // Dequeue one element and show updated queue
    dequeue(&front, &rear);
    printf("\nAfter one dequeue:\n");
    display(front);

    return 0;
}
