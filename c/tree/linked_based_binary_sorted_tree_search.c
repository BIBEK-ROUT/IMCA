#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct llb {
    int data;
    struct llb *left, *right;
} llb;

bool found = false;

llb* create_node(int data) {
    llb* node = (llb*)malloc(sizeof(llb));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void create_sorted_tree(llb **head, int data) {
    if (*head == NULL) {
        *head = create_node(data);
    } else if (data < (*head)->data) {
        create_sorted_tree(&((*head)->left), data);
    } else if (data > (*head)->data) {
        create_sorted_tree(&((*head)->right), data);
    } else {
        printf("The data %d is already inserted.\n", data);
    }
}

void search(int data, llb *current, llb *parent) {
    if (current == NULL)
        return;

    if (current->data == data) {
        found = true;
        if (parent == NULL) {
            printf("The data %d is found at the ROOT node.\n", data);
        } else if (parent->left == current) {
            printf("The data %d is found as LEFT child of %d.\n", data, parent->data);
        } else if (parent->right == current) {
            printf("The data %d is found as RIGHT child of %d.\n", data, parent->data);
        }
        return;
    }

    if (data < current->data) {
        search(data, current->left, current);
    } else {
        search(data, current->right, current);
    }
}

int main() {
    llb *head = NULL;
    int data;
    char ch;

    do {
        printf("Enter the data: ");
        scanf("%d", &data);
        create_sorted_tree(&head, data);
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &ch);  // note the space before %c
    } while (ch == 'y' || ch == 'Y');

    printf("Enter the data to search: ");
    scanf("%d", &data);
    search(data, head, NULL);

    if (!found) {
        printf("The data %d is NOT found in the tree.\n", data);
    }

    return 0;
}
