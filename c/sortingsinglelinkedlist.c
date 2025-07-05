#include<stdio.h>
#include<stdlib.h>
typedef struct singlelinkedlist{
    int data;
    struct singlelinkedlist *next;
}sll;
void create(sll **head,int data)
{
    sll *node=(sll *)malloc(sizeof(sll));
    node->data=data;
    node->next=NULL;
    if(*head==NULL)
    *head=node;
    else{
        sll *temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=node;
    }
}
void display(sll *head){
    sll *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void sort(sll *head){
    sll *temp=head,*temp1=NULL;
    while(temp!=NULL)
    {
        temp1=temp->next;
        while(temp1!=NULL)
        {
            if((temp->data)>(temp1->data))
            {
                int temp2=temp->data;
                temp->data=temp1->data;
                temp1->data=temp2;
            }
            temp1=temp1->next;
        }
        temp=temp->next;
    }

}
int main()
{
    sll *head=NULL;
    int data;
    char ch='y';
    while(ch=='y')
    {
        printf("please enter the data you want to insert:\n");
        scanf("%d",&data);
        create(&head,data);
        getchar();
        printf("if you want to insert another data in the list press y:");
        scanf("%c",&ch);
    }
    display(head);
    sort(head);
    display(head);
}