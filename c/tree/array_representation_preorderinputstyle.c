#include <stdio.h>
#include <stdlib.h>

// Function to create the binary tree
void create_tree(int *arr, int i, int n, int num, int *count) {
    if (i >= n) {
        // Prevent insertion beyond array bounds
        printf("⚠  Cannot insert at index %d — array size limit reached!\n", i);
        return;
    }

    arr[i] = num;  // Insert current node value at index i

    char ch;
    int child_num;

    // Ask to insert left child
    printf("\nInsert LEFT child of %d? (y/n): ", num);
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') {
        if (*count >= n - 1) {
            printf("⚠  Tree is full! Cannot insert more nodes.\n");
            return;
        }
        printf("Enter value for LEFT child of %d: ", num);
        scanf("%d", &child_num);
        (*count)++;
        create_tree(arr, 2 * i + 1, n, child_num, count);  // Recurse to left child
    }

    // Ask to insert right child
    printf("\nInsert RIGHT child of %d? (y/n): ", num);
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') {
        if (*count >= n - 1) {
            printf("⚠  Tree is full! Cannot insert more nodes.\n");
            return;
        }
        printf("Enter value for RIGHT child of %d: ", num);
        scanf("%d", &child_num);
        (*count)++;
        create_tree(arr, 2 * i + 2, n, child_num, count);  // Recurse to right child
    }
}

// Function to display the tree as an array
void display_array(int *arr, int n) {
    printf("\n📦 Tree Array Representation:\n");
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            printf(". ");  // Show empty position
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

// Inorder Traversal (Left → Root → Right)
void display_inorder(int *arr, int i, int n) {
    if (i >= n || arr[i] == -1) return;
    display_inorder(arr, 2 * i + 1, n);
    printf("%d ", arr[i]);
    display_inorder(arr, 2 * i + 2, n);
}

// Preorder Traversal (Root → Left → Right)
void display_preorder(int *arr, int i, int n) {
    if (i >= n || arr[i] == -1) return;
    printf("%d ", arr[i]);
    display_preorder(arr, 2 * i + 1, n);
    display_preorder(arr, 2 * i + 2, n);
}

// Postorder Traversal (Left → Right → Root)
void display_postorder(int *arr, int i, int n) {
    if (i >= n || arr[i] == -1) return;
    display_postorder(arr, 2 * i + 1, n);
    display_postorder(arr, 2 * i + 2, n);
    printf("%d ", arr[i]);
}

// Main Function
int main() {
    int n, root_data;

    // Ask for array size
    printf("Enter the maximum size of the binary tree (array size): ");
    scanf("%d", &n);

    // Dynamically allocate array and initialize with -1
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr[i] = -1;

    // Read root node
    printf("Enter value for ROOT node: ");
    scanf("%d", &root_data);

    int count = 1;  // Count how many nodes have been inserted (starts with root)
    create_tree(arr, 0, n, root_data, &count);

    // Show tree in various forms
    display_array(arr, n);

    printf("\n🧭 Inorder Traversal   : ");
    display_inorder(arr, 0, n);

    printf("\n🚀 Preorder Traversal  : ");
    display_preorder(arr, 0, n);

    printf("\n🎯 Postorder Traversal : ");
    display_postorder(arr, 0, n);

    printf("\n");

    // Free memory
    free(arr);
    return 0;
}