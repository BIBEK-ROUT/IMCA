#include<stdio.h>
#include<stdlib.h>
typedef struct single_linked_list
{
    int data;
    struct single_linked_list *next;
}sll;
void create(sll **head,sll **last,int data)
{
    sll *temp=*head,*node=NULL;
    node=(sll *)malloc(sizeof(sll));
    if(node==NULL)
    {
        printf("memory allocation failed!!");
        exit(1);
    }
    node->data=data;
    node->next=NULL;
    if(*head==NULL)
    {
        *head=node;
        *last=node;
    }
    else{
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=node;
        *last=node;
    }
}
void delete_any(sll **head,int data)
{
    sll *temp=*head,*prev=NULL;
    while(temp!=NULL)
    {
        prev=temp;
        if(temp->data=data)
        {
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Element not found!!\n");
        return;
    }
    if(temp==*head)
    {
        *head=temp->next;
    }
    else
    {
        prev->next=temp->next;
    }
    free(temp);
    printf("Element deleted successfully!!\n");
    return;
}
void reverse(sll **head)
{
    sll *p1=*head,*p2=p1->next,*p3=p2->next;
    p2->next=p1;
    p1->next=NULL;
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->next;
        p2->next=p1;
    }
    *head=p2;
}
void display(sll *head)
{
  while(head!=NULL)  
  {
    printf("%d->",head->data);
    head=head->next;
  }
  printf("NULL");
}
int main()
{
    sll *head=NULL,*last=NULL;
    int data;
    char ch;
    printf("if want to insert data in the list press y:");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        printf("Enter the data to insert:");
        scanf(" %d",&data);
        create(&head,&last,data);

        printf("if want to insert again press y:");
        scanf(" %c",&ch);
    }
    printf("Display the elements:");
    display(head);
    reverse(&head);
    printf("\n Display the elements after reverse:");
    display(head);
    return 0;
}