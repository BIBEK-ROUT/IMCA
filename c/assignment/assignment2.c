#include<stdio.h>
#include<stdlib.h>
typedef struct singlelinkedlist
{
    int data;
    struct singlelinkedlist *next;
}sll;

sll* traverse(sll *temp)
{
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    return temp;
}

void display(sll *temp)
{
    //sll *temp=node;
    if(!temp)
    {
        printf("\nlist is empty");
        exit(1);
    }
    while(temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
}

void create(sll** head,int num)
{
    sll* node=NULL,*last=NULL;
    node=(sll*)malloc(sizeof(sll));
    if(node==NULL)
    {
        printf("\nMemory allocation Failure!!");
        exit(1);
    }
    node->data=num;
    node->next=NULL;
    if(*head==NULL)
    {
        *head=node;
    }
    else 
    {
        last=traverse(*head);
        last->next=node;
    }
}

void reverse(sll** head)
{
    sll* p1,*p2,*p3;
    p1=*head;
    p2=p1->next;
    p3=p2->next;
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

void sort(sll** head)
{
    sll*i=NULL,*j=NULL;
    int temp;
    for(i=*head;i!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data > j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}

void insertAny(sll **head,int num,int pos)
{
    int count=1;
    sll* node=NULL,*prev=NULL,*temp=*head,*last=NULL;
    node=(sll*)malloc(sizeof(sll));
    if(node==NULL)
    {
        printf("\nMemory allocation Failure!!");
        exit(1);
    }
    node->data=num;
    node->next=NULL;
    if(*head==NULL)
    {
        *head=node;
        return;
    }
    if(pos==1)
    {
        node->next=*head;
        *head=node;
        return;
    }
    while(count!=pos && temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
        count++;
    }
    if(count==pos)
    {
        node->next=temp;
        prev->next=node;
        return;
    }
    else if(temp->next==NULL && count==pos-1)
    {
        temp->next=node;
        return;
    }
    else
    {
        printf("\ninvalid position");
    }
}

void delete_end(sll** head)
{
    
    sll* temp=*head,*prev=NULL;
    if(*head==NULL)
    {
        printf("\nList is empty");
        return;
    }
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL)
    {
        *head=NULL;
        free(temp);
        return;
    }
    else
    {
        prev->next=NULL;
        free(temp);
        return;
    }
}

int main()
{
    sll* head = NULL;
    int choice, num, pos;
    char ch;

    do {
        printf("\n\n====== MENU ======");
        printf("\n1. Create Node");
        printf("\n2. Display List");
        printf("\n3. Reverse List");
        printf("\n4. Sort List");
        printf("\n5. Insert at Any Position");
        printf("\n6. Delete from End");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("\nEnter the number: ");
                    scanf("%d", &num);
                    create(&head, num);
                    printf("Do you want to add more (y/n)? ");
                    getchar(); // Clear newline from buffer
                    scanf("%c", &ch);
                } while (ch == 'y' || ch == 'Y');
                break;

            case 2:
                display(head);
                break;

            case 3:
                reverse(&head);
                printf("\nList reversed.");
                break;

            case 4:
                sort(&head);
                printf("\nList sorted.");
                break;

            case 5:
                printf("\nEnter the data and position: ");
                scanf("%d%d", &num, &pos);
                insertAny(&head, num, pos);
                break;
            case 6:
                delete_end(&head);
                break;

            case 7:
                printf("\nExiting...");
                exit(0);

            default:
                printf("\nInvalid choice. Try again.");
        }

    } while (1);

    return 0;
}