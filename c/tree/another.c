#include <stdio.h>
#include <stdlib.h>

void create_tree(int *arr, int i, int n) {
    int data;

    // Base case: if index is out of range
    if (i >= n) return;

    printf("Enter data for node at index %d (-1 for NULL): ", i);
    scanf("%d", &data);

    arr[i] = data;

    // If this is a null node, do not create children
    if (data == -1) return;

    // Create left and right children using index rules
    create_tree(arr, 2 * i + 1, n); // left child
    create_tree(arr, 2 * i + 2, n); // right child
}

void display_inorder(int *arr, int i, int n) {
    if (i >= n || arr[i] == -1) return;

    display_inorder(arr, 2 * i + 1, n); // left
    printf("%d ", arr[i]);              // root
    display_inorder(arr, 2 * i + 2, n); // right
}
void display(int *arr,int n)
{
    for (int i=0;i<n;i++)
    {
            if(arr[i]!=-1)
        printf("%d\n",arr[i]);
    }
}
int main() {
    int n;
    printf("Enter the maximum number of nodes in tree: ");
    scanf("%d", &n);

    // Initialize tree array with -1s
    int *arr = (int*)malloc(sizeof(int) * n);
   // for (int i = 0; i < n; i++) arr[i] = -1;

    // Build tree starting from root index 0
    create_tree(arr, 0, n);

    printf("\nInorder Traversal: ");
    display_inorder(arr, 0, n);
    printf("\ndisplay:");
    display(arr,n);
    free(arr);
    return 0;
}