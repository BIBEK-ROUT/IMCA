#include<stdio.h>
#include<stdlib.h>
typedef struct circularlinkedlist
{
    int data;
    struct circularlinkedlist *next;
}cssl;
void create(cssl **head,int data)
{
    cssl *node=NULL;
    node=(cssl *)malloc(sizeof(cssl));
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
        node->next=*head;
    }
    else
    {
        cssl *temp=*head;
        while(temp->next!=*head)
        {
            temp=temp->next;
        }
        temp->next=node;
        node->next=*head;
    }
}
void display(cssl *head)
{
    cssl*temp=head;
   do
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
     while(temp!=head);
}
void insert_end(cssl *head,int data)
{
    cssl *temp=head;
    cssl *node=NULL;
    node=(cssl *)malloc(sizeof(cssl));
    if(node==NULL)
    {
        printf("the memory allocation failed!!!");
        exit(1);
    }
    node->data=data;
    node->next=NULL;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=node;
    node->next=head;

}
void insert_begining(cssl **head,int data)
{
    cssl *node=NULL;
    node=(cssl *)malloc(sizeof(cssl));
    if(node==NULL)
    {
        printf("memory allocation failed!!");
        exit(1);
    }
    node->data=data;
    node->next=NULL;
    cssl *temp=*head;
    node->next=temp;
    *head=node;
    cssl *temp1 = temp;
    while (temp1->next != temp) {
    temp1 = temp1->next;
    }
    temp1->next = *head;

}
int count(cssl *head)
{
    int count=0;
    cssl *temp=head;
    do
    {
        temp=temp->next;
        count++;
    } while (temp!=head);
    return count;
    
}
cssl* get_node_at(cssl *head, int pos) {
    cssl *temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    return temp;
}

void swap(cssl *head,int pos1,int pos2)
{
    cssl *temp=head,*req1,*req2;
    int i=1,temp1;
    do
    {
        if(i==pos1)
        {
            req1=temp;
        }
        else if(i==pos2)
        {
            req2=temp;
        }
        i++;
        temp=temp->next;
    }
    while(temp!=head);
    temp1=req1->data;
    req1->data=req2->data;
    req2->data=temp1;
}
void selection_sort(cssl *head) {
    int i = 1, j, k = count(head), min;
    cssl *req1, *req2;

    while (i <= k) {
        req1 = get_node_at(head, i);    
        req2 = req1->next;
        j = i + 1;
        min = i;

        while (j <= k) {
            if (req2->data < req1->data) {
                req1 = req2;            
                min = j;
            }
            req2 = req2->next;
            j++;
        }

        if (min != i) {
            swap(head, i, min);          
        }

        i++;
    }
}

    int main()
{
    int data;
    char ch;
    cssl *head = NULL;
    printf("please press y if you want to insert any data in the list:");
    scanf(" %c", &ch); // Notice the space before %c

    while (ch == 'y')
    {
        printf("please enter the data you want to insert:");
        scanf("%d", &data);

        create(&head, data);

        printf("if you want to insert data again press y:");
        scanf(" %c", &ch); // Space before %c skips any whitespace (including \n)
    }
    display(head);
   printf("\nplease enter the data you want to insert:");
    scanf("%d",&data);
    insert_begining(&head,data);
    fflush(stdin);
    printf("please enter the data you want to insert:");
    scanf("%d",&data);
    insert_end(head,data);
    display(head);
    printf("\nlist after sorting:\n");
    selection_sort(head);
    display(head);
}
