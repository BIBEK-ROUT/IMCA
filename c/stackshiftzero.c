#include<stdio.h>
#include<stdlib.h>
int *stack;
int size;
int top=0,count=0;
void push(int data)
{
    if(count==0)
    {
        stack[top]=data;
        count++;
        return;
    }
    for(int i=count;i>=0;i--)
    {
        stack[i+1]=stack[i];
    }
    stack[top]=data;
    count++;
    return;
}
void pop()
{
if(count==0)
{
    printf("stack underflow!!");
    return ;
}
for(int i=1;i<count;i++)
{
    stack[i-1]=stack[i];
}
count=count-1;
return;
}
void display()
{ 
    if(count==0)
    {
        printf("stack is empty!!");
        return;
    }
    for(int i=0;i<count;i++)
    {
        printf("%d",stack[i]);
    }
}
int main()
{
    int data;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    stack = (int *)malloc(size * sizeof(int));
    for(int i=0;i<size;i++)
    {
        printf("please enter the data to push:");
        scanf("%d",&data);
        push(data);
    }
    printf("displaying all the elements:\n");
     display();
     pop();
     pop();
    printf("\ndisplaying elements after pop\n");
    display();
}