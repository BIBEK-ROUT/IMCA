#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct selectionsort_linkedlist {
    int data;
    struct selectionsort_linkedlist *next;
} sll;

// Function to create and append a new node to the list
void create(sll **head, sll **last, int data) {
    sll *node = (sll *)malloc(sizeof(sll));

    // Memory allocation check
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->data = data;
    node->next = NULL;

    // If the list is empty, initialize head and last
    if (*head == NULL) {
        *head = node;
        *last = node;
    } else {
        // Append the new node at the end
        (*last)->next = node;
        *last = node;
    }
}

// Function to display the entire linked list
void display(sll *head) {
    sll *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to perform selection sort on the linked list (by swapping data)
void selection_sort(sll **head) {
    sll *temp1 = *head, *temp2, *min;
    int temp_data;

    // Edge case: empty list
    if (*head == NULL)
        return;

    // Outer loop to fix one node at a time
    while (temp1 != NULL) {
        min = temp1;
        temp2 = temp1->next;

        // Find node with the minimum value in remaining list
        while (temp2 != NULL) {
            if (temp2->data < min->data) {
                min = temp2;
            }
            temp2 = temp2->next;
        }

        // Swap data between current and min node
        if (min != temp1) {
            temp_data = temp1->data;
            temp1->data = min->data;
            min->data = temp_data;
        }

        temp1 = temp1->next;
    }
}

// Main function to drive the program
int main() {
    sll *head = NULL, *last = NULL;
    int data;
    char ch;

    printf("========== Linked List Creation ==========\n");
    printf("Press 'y' to insert a node, any other key to stop: ");
    scanf(" %c", &ch);  // Notice the space before %c to clear newline

    while (ch == 'y' || ch == 'Y') {
        printf("Enter data: ");
        scanf("%d", &data);

        create(&head, &last, data);

        printf("Insert another node? (y/n): ");
        scanf(" %c", &ch);  // Again, clear newline
    }

    printf("\n========== Original List ==========\n");
    display(head);

    printf("\n========== Performing Selection Sort ==========\n");
    selection_sort(&head);

    printf("\n========== Sorted List ==========\n");
    display(head);

    return 0;
}
