#include<stdio.h>
#include<stdlib.h>
int size,top=-1;
int stack[400];
void push(int data)
{
    if(top==size-1)
    {
        printf("stack overflow!!");
        return;
    }
    stack[++top]=data;
}
int pop()
{
    if(top==-1)
    {
        printf("stack memory underflow!!");
        return -1;
    }
    size=size-1;
    return stack[--top];
}
void display()
{
    if(top==-1)
    {
        printf("the stack is empty!!");
        return ;
    }
    for(int i=0;i<size;i++)
    {
        printf("%d",stack[i]);
    }
}
int main()
{
    int i,data;
    printf("please enter the size of the stack:");
    scanf(" %d",&size);
    for(i=0;i<size;i++)
    {
        printf("please enter the data for position %d:",i);
        scanf(" %d",&data);
        push(data);
    }
    pop();
    display();
}