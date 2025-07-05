#include <stdio.h>
#include <stdlib.h>

typedef struct doublelinkedlist {
    struct doublelinkedlist *prev;
    int data;
    struct doublelinkedlist *next;
} dll;

// Create and insert at end
void create(dll **head, int data) {
    dll *node = (dll *)malloc(sizeof(dll));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    if (*head == NULL) {
        *head = node;
    } else {
        dll *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
}

void display(dll *head) {
    dll *temp = head;
    printf("List: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_beginning(dll **head, int data) {
    dll *node = (dll *)malloc(sizeof(dll));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->prev = NULL;
    node->next = *head;
    if (*head != NULL)
        (*head)->prev = node;
    *head = node;
}

void insert_end(dll **head, int data) {
    create(head, data);
}

int count(dll *head) {
    int i = 0;
    while (head != NULL) {
        head = head->next;
        i++;
    }
    return i;
}

void delete_at_position(dll **head, int pos) {
    if (*head == NULL || pos < 1) {
        printf("Invalid position or empty list.\n");
        return;
    }
    dll *temp = *head;
    int i = 1;
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    if (temp->prev)
        temp->prev->next = temp->next;
    else // Deleting head
        *head = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    free(temp);
}

void insert_at_position(dll **head, int pos, int data) {
    if (pos < 1 || pos > count(*head) + 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        insert_beginning(head, data);
        return;
    }
    dll *temp = *head;
    int i = 1;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }
    dll *node = (dll *)malloc(sizeof(dll));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->next = temp->next;
    node->prev = temp;
    if (temp->next)
        temp->next->prev = node;
    temp->next = node;
}

void free_list(dll *head) {
    dll *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int data, num, pos;
    char ch;
    dll *head = NULL;

    // Create initial list
    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        create(&head, data);
        printf("Insert more data? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    display(head);

    // Insert at beginning
    printf("Insert at beginning? (y/n): ");
    scanf(" %c", &ch);
    while (ch == 'y' || ch == 'Y') {
        printf("Enter data to insert at beginning: ");
        scanf("%d", &num);
        insert_beginning(&head, num);
        display(head);
        printf("Insert more at beginning? (y/n): ");
        scanf(" %c", &ch);
    }

    // Insert at end
    printf("Insert at end? (y/n): ");
    scanf(" %c", &ch);
    while (ch == 'y' || ch == 'Y') {
        printf("Enter data to insert at end: ");
        scanf("%d", &num);
        insert_end(&head, num);
        display(head);
        printf("Insert more at end? (y/n): ");
        scanf(" %c", &ch);
    }

    // Delete at position
    printf("Delete at position? (y/n): ");
    scanf(" %c", &ch);
    while (ch == 'y' || ch == 'Y') {
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        delete_at_position(&head, pos);
        display(head);
        printf("Delete more? (y/n): ");
        scanf(" %c", &ch);
    }

    // Insert at position
    printf("Insert at position? (y/n): ");
    scanf(" %c", &ch);
    while (ch == 'y' || ch == 'Y') {
        printf("Enter position to insert: ");
        scanf("%d", &pos);
        printf("Enter data to insert: ");
        scanf("%d", &num);
        insert_at_position(&head, pos, num);
        display(head);
        printf("Insert more? (y/n): ");
        scanf(" %c", &ch);
    }

    printf("Number of nodes: %d\n", count(head));
    free_list(head);
    return 0;
}
