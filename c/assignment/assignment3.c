#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct doublelinkedlist {
    struct doublelinkedlist* prev;
    char data;
    struct doublelinkedlist* next;
} dll;

void create(dll **head, dll **last, char ch);
void insert(dll **head, dll **last, char ch);
void delete_any(dll **head, dll **last, int pos);
void fdisplay(dll *head);
void bdisplay(dll *last);

int main() {
    dll *head = NULL, *last = NULL;
    int choice, i;
    char s[50], ch;

    while (1) {
        printf("\n----- MENU -----");
        printf("\n1. Create from string");
        printf("\n2. Display forward");
        printf("\n3. Display backward");
        printf("\n4. Insert character at beginning");
        printf("\n5. Delete from any position");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("\nEnter the string: ");
                fgets(s, sizeof(s), stdin);
                if (s[strlen(s) - 1] == '\n')
                    s[strlen(s) - 1] = '\0';
                for (i = 0; i < strlen(s); i++) {
                    create(&head, &last, s[i]);
                }
                break;

            case 2:
                printf("\nForward Display: ");
                fdisplay(head);
                printf("\n");
                break;

            case 3:
                printf("\nBackward Display: ");
                bdisplay(last);
                printf("\n");
                break;

            case 4:
                printf("\nEnter the character you want to insert at beginning: ");
                scanf(" %c", &ch);
                insert(&head, &last, ch);
                break;

            case 5:
                printf("\nEnter the position you want to delete: ");
                scanf("%d", &i);
                delete_any(&head, &last, i);
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid choice. Try again.");
        }
    }

    return 0;
}

void create(dll **head, dll **last, char ch) {
    dll *node = (dll *)malloc(sizeof(dll));
    if (node == NULL) {
        printf("\nMemory allocation Failure..");
        return;
    }
    node->prev = NULL;
    node->data = ch;
    node->next = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        (*last)->next = node;
        node->prev = *last;
    }
    *last = node;
}

void insert(dll **head, dll **last, char ch) {
    dll *node = (dll *)malloc(sizeof(dll));
    if (node == NULL) {
        printf("\nMemory allocation Failure..");
        return;
    }
    node->prev = NULL;
    node->data = ch;
    node->next = *head;
    if (*head != NULL) {
        (*head)->prev = node;
    } else {
        *last = node; // If list was empty, last also points to new node
    }
    *head = node;
}

void fdisplay(dll *head) {
    while (head != NULL) {
        printf("%c->", head->data);
        head = head->next;
    }
    printf("NULL");
}

void bdisplay(dll *last) {
    while (last != NULL) {
        printf("%c->", last->data);
        last = last->prev;
    }
    printf("NULL");
}

void delete_any(dll **head, dll **last, int pos) {
    dll *temp = *head, *previous = NULL;
    int count = 1;
    if (*head == NULL) {
        printf("\nList is empty!!");
        return;
    }
    if (pos == 1) {
        *head = temp->next;
        if (*head)
            (*head)->prev = NULL;
        else
            *last = NULL; // List became empty
        free(temp);
        return;
    }
    while (count != pos && temp->next != NULL) {
        previous = temp;
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL && count == pos) {
        previous->next = NULL;
        *last = previous;
        free(temp);
        return;
    }
    if (count == pos) {
        previous->next = temp->next;
        if (temp->next)
            temp->next->prev = previous;
        free(temp);
    } else {
        printf("\nInvalid position");
    }
}
