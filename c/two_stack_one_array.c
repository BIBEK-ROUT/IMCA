#include<stdio.h>
#include<stdlib.h>
int *stack;
int size;
int top=-1,top1;
void push(int data,int stacknum)
{
    if(stacknum==1)
    {
        if(top == size - 1)
        {
            printf("Stack 1 overflow!!\n");
            return;
        }
        stack[++top] = data;
    }
    else if(stacknum==2)
    {
        if(top1 == 0)
        {
            printf("Stack 2 overflow!!\n");
            return;
        }
        stack[--top1] = data;
    }
    else
    {
        printf("Invalid stack number!!\n");
    }
}
void pop(int stackman)
{
    if(stackman==1)
    {
        if(top==-1)
        {
            printf("stack no.1 underflow!!");
            return;
        }
        top--;
    }
    else if(stackman==2)
    {
        if(top==size)
        {
            printf("stack no.2 underflow!!");
            return;
        }
        top1++;
    }
}
void display()
{
    if(top == -1 && top1 == size)
    {
        printf("Both stacks are empty!!\n");
        return;
    }
    printf("Stack 1 elements are:\n");
    for(int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
    
    printf("Stack 2 elements are:\n");
    for(int i = size - 1; i >= top1; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main()
{
    int data,stacknum;
    printf("Enter the size of the stack:");
    scanf(" %d",&size);
    top1=size;
    stack = (int *)malloc(size * sizeof(int));
    if(stack == NULL)
    {
        printf("Memory allocation failed!!\n");
        return 1;
    }
    for(int i=0;i<size;i++)
    {
        printf("enter the data for stacks:");
        scanf(" %d",&data);
        printf("enter the stack number (1 or 2):");
        scanf(" %d",&stacknum);
        push(data, stacknum);
    }
    printf("displaying the stacks:\n");
    display();
    printf("Popping from stack 1:\n");
    pop(1);
    printf("Popping from stack 2:\n");
    pop(2);
    printf("displaying the stacks after popping:\n");
    display();
    return 0;
}