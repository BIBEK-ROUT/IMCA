#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int front;
    int rear;
    int size;
    int *arr;
}queue;
int isfull(queue *q)
{
    return ((q->rear+1)%q->size==q->front);
}
int isempty(queue *q)
{
    return(q->front==-1);
}
void enqueue(queue *q,int data)
{
    if(isfull(q))
    {
        printf("queue overflow.\n");
        return;
    }
    else if(isempty(q))
    {
        q->front=0;
        q->rear=0;
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
    }
    q->arr[q->rear]=data;
}
int dequeue(queue *q)
{
    if(isempty(q))
    {
        printf("queue underflow.\n");
        return -1;
    }
    int data=q->arr[q->front];
    if(q->front==q->rear)
    {
        q->front=-1;
        q->rear=-1;
    }
    else
    {
    q->front=(q->front+1)%q->size;
    }
    return data;
}
void display(queue *q)
{
    if(isempty(q))
    {
        printf("queue is empty.\n");
        return;
    }
    int i=q->front;
    while (1)
    {
        printf("%d",q->arr[i]);
        if(i==q->rear)
        {
            break;
        }
        i=(i+1)%q->size;
    }
    printf("\n");
}
void rotate(queue *q,int k)
{
    int data;
    for(int i=0;i<k;i++)
    {
        printf("dequeued element:%d",data=dequeue(q));
        enqueue(q,data);
    }
}
int main()
{
     int data,k;
     char ch;
     queue q;
     q.front=-1;
     q.rear=-1;
     printf("Please enter the size of the queue:");
     scanf("%d",&q.size);
     q.arr=NULL;
     q.arr=(int *)malloc(sizeof(int)*q.size);
     if(q.arr==NULL)
     {
        printf("Memory allocation failled!!");
        exit (1);
     }
     printf("Press 'y' if you wnat to enqueue data in the queue:");
     scanf(" %c",&ch);
     while((ch=='y'||ch=='Y')&&!isfull(&q))
     {
        printf("Please enter the data:");
        scanf(" %d",&data);
        enqueue(&q,data);
        printf("Press 'y' if you want to insert again:");
        scanf(" %c",&ch);
     }
     display(&q);
     printf("Please enter the no.of elements to rotate:");
     scanf("%d",&k);
     if(k>q.size || k<0)
     {
        printf("Invalid input!!");
        exit (1);
     }
     else
     {
        rotate(&q,k);
     }
     printf("\nThe queue after rotation is:");
        display(&q);
     return 0;
}