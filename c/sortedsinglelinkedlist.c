#include<stdio.h>
#include<stdlib.h>
typedef struct singlelinkedlist{
    int data;
    struct singlelinkedlist *next;
} sll;
void insert_end(sll *head,sll *node){
    sll *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node;
}
void create(sll **head,int data){
    sll *temp=*head;
    sll *temp1=*head;
    sll *prev;
    sll *node=NULL;
    int found=0;
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
        return;
    }
    if(node->data<(*head)->data)
    {
        node->next=temp1;
        (*head)=node;
    }
    else{
        while(temp->next!=NULL)
        {
            if(temp->data<node->data)
            {
                prev=temp;
            }
            temp=temp->next;
        }
        if(temp->data<node->data)
        prev=temp;
        if(prev->next!=NULL)
        {
            node->next=prev->next;
            prev->next=node;
            found=1;
        }
        if(found!=1)
        {
            insert_end(*head,node);
        }
    }
}
void display(sll *head)
{
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main()
{
    int data;
    char ch;
    sll *head=NULL;
    printf("please press y if you want to insert any data in the list:");
    scanf("%c",&ch);
    while(ch=='y')
    {
        printf("please enter the data you want to insert:");
        scanf("%d",&data);
        create(&head,data);
        getchar();
        printf("if you want to insert data again press y:");
        scanf("%c",&ch);
    }
    display(head);
}