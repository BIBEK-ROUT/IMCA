#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 100

int tree[max]; // Array representation of binary tree

// Build the binary tree recursively in array form
void Build_tree(int index, int data) {
    if (index >= max) return;

    char ch;
    tree[index] = data;

    // Ask for left child
    printf("If you want to enter left child of %d press y: ", tree[index]);
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') {
        printf("Enter the data: ");
        scanf(" %d", &data);
        Build_tree(2 * index + 1, data);
    }

    // Ask for right child
    printf("If you want to enter right child of %d press y: ", tree[index]);
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') {
        printf("Enter the data: ");
        scanf(" %d", &data);
        Build_tree(2 * index + 2, data);
    }
}

// Search the element in the tree and print its position
bool search(int data, int index) {
    if (index >= max || tree[index] == -1) return false;

    if (tree[index] == data) {
        if (index == 0) {
            printf("Element %d is the ROOT node.\n", data);
        } else {
            int parent = (index - 1) / 2;
            if (2 * parent + 1 == index)
                printf("Element %d is LEFT child of %d\n", data, tree[parent]);
            else
                printf("Element %d is RIGHT child of %d\n", data, tree[parent]);
        }
        return true;
    }

    // Search in left or right subtree
    return search(data, 2 * index + 1) || search(data, 2 * index + 2);
}

// Display all non-empty elements of the tree
void display() {
    printf("\nBinary Tree (Array Representation):\n");
    for (int i = 0; i < max; i++) {
        if (tree[i] != -1)
            printf("tree[%d] = %d\n", i, tree[i]);
    }
}

int main() {
    // Initialize tree with -1 (empty slots)
    for (int i = 0; i < max; i++)
        tree[i] = -1;

    int data;
    printf("Enter the data for root node: ");
    scanf(" %d", &data);

    // Build the tree
    Build_tree(0, data);

    // Display all nodes
    display();

    // Search for a specific value
    printf("\nEnter the number you want to search: ");
    scanf("%d", &data);

    // Search and print the result
    if (!search(data, 0))
        printf("Element %d not found in the tree.\n", data);

    return 0;
}
