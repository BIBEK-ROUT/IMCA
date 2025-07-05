#include<stdio.h>
#include<stdlib.h>
int *stack;
int size;
int top = -1;
int min=0;
void push(int data)
{
    int encoded = 2*data-min; // Store the original data
    if (top == -1) {
        min = data; 
        stack[++top]=data;
        return;// Initialize min with the first element
    } else if (data < min) {
        min =data; // Update min if the new data is smaller
        stack[++top] = encoded; // Store the encoded value
        return;
    }

    if(top==size-1)
    {
        printf("Stack overflow!!\n");
        return;
    }
    stack[++top] = data;
}
void pop()
{
    if(top==-1)
    {
        printf("Stack underflow!!\n");
        return;
    }
    if(stack[top] < min) {
        min = 2 * min - stack[top]; // Update min when popping an encoded value
    }
    top--;
}
void display()
{
    if(top==-1)
    {
        printf("Stack is empty!!\n");
        return;
    }
    printf("Stack elements are:\n");
    for(int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main()
{
    int data;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    stack = (int *)malloc(size * sizeof(int));
    
    printf("Enter the elements of the stack:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &data);
        push(data);
    }
    printf("Stack elements after pushing:\n");
     display();
    printf("Minimum element in the stack: %d\n", min);
    printf("Popping an element from the stack...\n");
    pop();
    printf("Stack elements after popping:\n");
    display();
    printf("Minimum element in the stack: %d\n", min);
    free(stack);
    return 0;
}