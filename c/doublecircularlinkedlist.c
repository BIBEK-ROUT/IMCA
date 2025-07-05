#include <stdio.h>
#include <stdlib.h>
typedef struct double_circular_list
{
    struct double_circular_list *prev;
    int data;
    struct double_circular_list *next;
} dcl;
void create(dcl **head, int data)
{
    dcl *temp = *head, *node = NULL, *temp1 = *head;
    node = (dcl *)malloc(sizeof(dcl));
    if (node == NULL)
    {
        printf("memory allocation failed!!!");
        exit(1);
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    if (*head == NULL)
    {
        *head = node;
        node->next = *head;
        node->prev = *head;
    }
    else
    {
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->next = *head;
        node->prev = temp;
        temp1->prev = node;
    }
}
int count(dcl *head)
{
    int count = 0;
    dcl *temp = head;
    do
    {
        count = count + 1;
        temp = temp->next;
    } while (temp != head);
    return count;
}
void display(dcl *head)
{
    dcl *temp = head;
    do
    {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void display_reverse(dcl *head)
{
    dcl *temp=head;
    do
    {
        temp=temp->prev;
        printf("%d->",temp->data);
    }
    while(temp!=head);
    
}
void delete_any(dcl **head, int pos)
{
    int j=count(*head);
    dcl *temp = *head,*temp1=*head;
    if (pos != 1 && pos != j)
    {
        for (int i = 1; i <pos; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    else if (pos == 1)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        *(head)=temp->next;
        free(temp);
    }
    else if(pos==j)
    {
        do
        {
            temp = temp->next;
        } while (temp->next!= *head);
        temp->prev->next=*head;
        temp1->prev=temp->prev;
        free(temp);
    }
    else
    {
        printf("\ninvlid position.");
        return;
    }
}
void insert_any(dcl **head,int data,int pos)
{
    dcl *temp=*head,*node=NULL;
    int j=count(*head);
    node=(dcl *)malloc(sizeof(dcl));
    if(node==NULL)
    {
        printf("\nmemory allocation is failed!!!");
        exit(1);
    }
    node->data=data;
    node->next=NULL;
    node->prev=NULL;
    if(pos!=1 && pos!=j)
    {
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        node->next=temp->next;
        temp->next->prev=node;
        node->prev=temp;
        temp->next=node;
    }
    else if(pos==1)
    {
        node->next=temp;
        node->prev=temp->prev;
        temp->prev->next=node;
        temp->prev=node;
        *head=node;
    }
    else if(pos==j+1)
    {
        temp->prev->next=node;
        node->prev=temp->prev;
        node->next=temp;
        temp->prev=node;
    }
    else if(pos==j)
    {
        node->prev=temp->prev->prev;
        node->next=temp->prev;
        temp->prev->prev->next=node;
        temp->prev->prev=node;
    }
    else
    {
        printf("the position is invalid.");
        exit(1);
    }
}
void sort(dcl **head)
{
    dcl *temp=*head,*temp1=temp->next,*temp2;
    int i,k;
    for(i=2;i<=count(*head);i++)
    {
        k=temp1->data;
        temp2=temp1->prev;
        while(temp2!=*head && temp2->data>k)
        {
            temp2->next->data=temp2->data;
            temp2=temp2->prev;
        }
        if(temp2==*head && temp2->data>k)
        {
            temp2->next->data=temp2->data;
            temp2->data=k;
        }
        else
        temp2->next->data=k;
        temp1=temp1->next;
    }
}
int main()
{
    int data,pos;
    dcl *head = NULL;
    char ch;
    printf(" please press y if you want insert element in th list:");
    scanf(" %c", &ch);
    while (ch == 'y')
    {
        printf("please enter the data you want to insert:");
        scanf(" %d", &data);
        create(&head, data);
        printf("\n if you want to insert more press y: ");
        scanf(" %c", &ch);
    }
    display(head);
    printf("\nthe no.of nodes present in the list is %d:",count(head));
    printf("\n if you want to delete any element in the list press y:");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        printf("please enter the position you want to delete:");
        scanf(" %d",&data);
        delete_any(&head,data);
        printf("\nif you want delte again press y:");
        scanf(" %c",&ch);
    }
    display(head);
    printf("\n if you want to insert any element in the list press y:");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        printf("please enter the data you want to insert:");
        scanf(" %d",&data);
        printf("\n please enter the postion you want to insert:");
        scanf(" %d",&pos);
        insert_any(&head,data,pos);
        printf("\nif you want insert again press y:");
        scanf(" %c",&ch);
    }
    display(head);
    printf("\nthe no.of nodes present in the list is %d:",count(head));
    display_reverse(head);
    printf("\n sort the list:\n");
    sort(&head);
    display(head);
}