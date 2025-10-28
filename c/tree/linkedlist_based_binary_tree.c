#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_tree {
    int data;
    struct linked_list_tree *left, *right;
} llt;

// Function to create a new node
llt* create_node(int data) {
    llt* node = (llt*)malloc(sizeof(llt));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive tree builder
void Build_tree(llt **head) {
    char dir;
    int data;

    printf("Enter the data: ");
    scanf("%d", &data);
    *head = create_node(data);  // Allocate node and assign to pointer

    // LEFT child
    printf("Do you want to enter left child of %d (y/n)? ", data);
    scanf(" %c", &dir);  // The space before %c consumes any leftover '\n'
    if (dir == 'y' || dir == 'Y') {
        Build_tree(&((*head)->left));
    }

    // RIGHT child
    printf("Do you want to enter right child of %d (y/n)? ", data);
    scanf(" %c", &dir);
    if (dir == 'y' || dir == 'Y') {
        Build_tree(&((*head)->right));
    }
}

// Preorder display (root-left-right)
void display(llt *head) {
    if (head == NULL) return;
    printf("%d ", head->data);
    display(head->left);
    display(head->right);
}
void display_inorder(llt *head)
{
    if (head == NULL) return;
    display_inorder(head->left);
    printf("%d ", head->data);
    display_inorder(head->right);
}
void display_postorder(llt *head)
{
    if (head == NULL) return;
    display_postorder(head->left);
    display_postorder(head->right);
    printf("%d ", head->data);
}
int main() {
    llt* head = NULL;
    printf("Building the binary tree...\n");
    Build_tree(&head);

    printf("The tree in preorder is:\n");
    display(head);
    printf("\nThe tree in inorder is:\n");
    display_inorder(head);
    printf("\nThe tree in postorder is:\n");
    display_postorder(head);
    return 0;
}
