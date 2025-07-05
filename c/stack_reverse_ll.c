#include<stdio.h>
#include<stdlib.h>
typedef struct single_stack_list{
    int data;
    struct single_stack_list *next;
}ssl;
ssl *head=NULL;
void push(int data)
{
    ssl *node=NULL;
    node=(ssl *)malloc(sizeof(ssl));
    if(node==NULL)
    {
        printf("memory allocation failed!!");
        exit (1);
    }
    node->data=data;
    node->next=head;
    head=node;
}
void pop()
{
    if(head==NULL)
    {
        printf("stack underflow!!");
        return;
    }
    ssl *temp=head;
    head=head->next;
    free(temp);
}
void display()
{
    if(head==NULL)
    {
        printf("Stack is empty!!\n");
        return;
    }
    ssl *temp=head;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reverse()
{
     
}
int main()
{
    char ch;
    int data;
    printf("if you want to create a list press y:");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        printf("Enter the data:");
        scanf(" %d",&data);
        push(data);
        printf("if want to insert again press y:");
        scanf(" %c",&ch);
    }
    printf("Displaying the elements:");
    display();
    pop();
    printf("Displaying the elements after poping:");
    display();
    return 0;
}
