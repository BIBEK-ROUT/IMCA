#include<stdio.h>
#include<stdlib.h>
int *stack;
int *axulariy_stack;
int size;   
int top = -1;
int min = -1;
void push(int data)
{
    if (top == size - 1) {
        printf("Stack overflow!!\n");
        return;
    }
    stack[++top] = data;  
    if (min == -1 || data <=axulariy_stack[min]) {
        min++;
        axulariy_stack[min] = data;
    } 
}
void pop()
{
    if (top == -1) {
        printf("Stack underflow!!\n");
        return;
    }
    if (stack[top] == axulariy_stack[min]) {
        min--;
    }
    top--;
}
int get_min()
{
    if (min == -1) {
        printf("Stack is empty!!\n");
        return -1;
    }
    return axulariy_stack[min];
}
void display()
{
    if (top == -1) {
        printf("Stack is empty!!\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = 0; i <= top; i++) {
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
    axulariy_stack = (int *)malloc(size * sizeof(int));
    
    printf("Enter the elements of the stack:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &data);
        push(data);
    }
    printf("Stack after pushing elements:\n");
    display();
    pop();
    printf("Stack after popping an element:\n");
    display();
    printf("Minimum element in the stack: %d\n", get_min());
}