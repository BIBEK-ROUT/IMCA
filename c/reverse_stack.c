#include<stdio.h>
#include<stdlib.h>
int *stack;
int size;
int top=-1;
void push(int data)
{
    if(top == size - 1)
    {
        printf("Stack overflow!!\n");
        return;
    }
    stack[++top] = data;
}
void pop()
{
    if(top == -1)
    {
        printf("Stack underflow!!\n");
        return;
    }
    top--;
}
void reverse()
{
    if(top == -1)
    {
        printf("Stack is empty!!\n");
        return;
    }
    int start = 0, end = top;
    while(start < end)
    {
        int temp = stack[start];
        stack[start] = stack[end];
        stack[end] = temp;
        start++;
        end--;
    }
}
void display()
{
    if(top == -1)
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
    
    // Push elements onto the stack
    for(int i = 0; i < size; i++)
    {
        printf("Please enter the data to push: ");
        scanf("%d", &data);
        push(data);
    }
    reverse();
    printf("Displaying all the elements after reversing:\n");
    display();
    free(stack);
    return 0;
}