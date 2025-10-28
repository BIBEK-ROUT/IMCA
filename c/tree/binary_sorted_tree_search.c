#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 100

int tree[max];
bool found = false; // Global flag for search result

// Insert into sorted binary tree (BST logic)
void create_sorted_tree(int data, int index) {
    if (index >= max) return;

    if (tree[index] == -1) {
        tree[index] = data;
        return;
    }

    if (data < tree[index]) {
        create_sorted_tree(data, 2 * index + 1);
    } else if (data > tree[index]) {
        create_sorted_tree(data, 2 * index + 2);
    } else {
        printf("The value %d is already in the tree. Skipping...\n", data);
    }
}

// Display non-empty tree elements
void display() {
    printf("\nBinary Search Tree (Array Representation):\n");
    for (int i = 0; i < max; i++) {
        if (tree[i] != -1)
            printf("tree[%d] = %d\n", i, tree[i]);
    }
    printf("\n");
}

// Search in the tree and print location info
void search(int index, int data) {
    if (index >= max || tree[index] == -1) return;

    if (tree[index] == data) {
        found = true;
        if (index == 0) {
            printf("The data %d is found at the ROOT node.\n", data);
        } else {
            int parent = (index - 1) / 2;
            if (2 * parent + 1 == index)
                printf("The data %d is found at the LEFT child of %d.\n", data, tree[parent]);
            else
                printf("The data %d is found at the RIGHT child of %d.\n", data, tree[parent]);
        }
        return;
    }

    if (data < tree[index])
        search(2 * index + 1, data);
    else
        search(2 * index + 2, data);
}
int main() {
    for (int i = 0; i < max; i++)
        tree[i] = -1;

    int data;
    char ch;

    // Continuous input until user says no
    do {
        printf("Enter data to insert into tree: ");
        scanf("%d", &data);
        create_sorted_tree(data, 0);

        printf("Do you want to insert more? (y/n): ");
        scanf(" %c", &ch);  // note space before %c to skip newline
    } while (ch == 'y' || ch == 'Y');

    display();

    // Search Section
    printf("Enter a number to search in the tree: ");
    scanf("%d", &data);
    found = false; // reset flag
    search(0, data);
    if (!found)
        printf("The data %d is NOT found in the tree.\n", data);

    return 0;
}
