#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int front = -1, rear = -1;
int tree[MAX];     // Array-based binary tree representation
int queue[MAX];    // Queue to track indices for level-order construction
int size = 0;      // Keeps track of the highest filled index in the tree

// Enqueue index into queue
void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue is full! Cannot track more nodes.\n");
        exit(1);
    }
    queue[++rear] = data;
}

// Dequeue index from queue
int dequeue() {
    if (front == rear) {
        return -1;  // Queue empty → no more nodes to process
    }
    return queue[++front];
}

// Function to build the tree using level-order input
void buildTree() {
    int index, data;

    printf("Enter root value: ");
    scanf("%d", &data);

    tree[0] = data;      // Root node placed at index 0
    size = 1;            // Tree size starts at 1
    enqueue(0);          // Enqueue root index for processing its children

    // Continue processing nodes level by level until queue is empty
    while ((index = dequeue()) != -1) {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        // Stop if we're about to go out of array bounds
        if (leftIndex >= MAX || rightIndex >= MAX)
            break;

        // LEFT CHILD
        printf("Enter left child of %d (-1 for NULL): ", tree[index]);
        scanf("%d", &data);
        tree[leftIndex] = data;
        if (data != -1) {                    // Only enqueue if child is not NULL
            enqueue(leftIndex);
            if (leftIndex >= size) size = leftIndex + 1;
        }

        // RIGHT CHILD
        printf("Enter right child of %d (-1 for NULL): ", tree[index]);
        scanf("%d", &data);
        tree[rightIndex] = data;
        if (data != -1) {
            enqueue(rightIndex);
            if (rightIndex >= size) size = rightIndex + 1;
        }
    }
}

// Function to display the tree (array representation)
void display() {
    printf("\nBinary Tree (Array Representation):\n");
    for (int i = 0; i < size; i++) {
       if (tree[i] != -1) {
            printf("tree[%d] = %d\n", i, tree[i]);
        } else {
            printf("tree[%d] = NULL\n", i);  // Display NULLs clearly
        }
    }
}
void inorder_display(int index)
{
    if(index>=size||tree[index]==-1) return;
    inorder_display(2*index+1);
    printf("%d",tree[index]);
    inorder_display(2*index+2);
}
void preorder_display(int index)
{
    if(index>=size||tree[index]==-1) return;
    printf("%d",tree[index]);
    preorder_display(2*index+1);
    preorder_display(2*index+2);
}
void postorder_display(int index)
{
    if(index>=size||tree[index]==-1) return;
    postorder_display(2*index+1);
    postorder_display(2*index+2);
    printf("%d",tree[index]);
}
int main() {
    // Initialize tree with all NULLs
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }

    // Build and display the tree
    buildTree();
    printf("Displaying in a normal way:");
    display();
    printf("\n Displaying in inorder traversal:");
    inorder_display(0);
    printf("\n Displaying in preorder traversal:");
    preorder_display(0);
    printf("\n Displaying in postorder traversal:");
    postorder_display(0);
    return 0;
}
