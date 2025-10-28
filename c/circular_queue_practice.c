#include<stdio.h>
#include<stdlib.h>
typedef struct circular_queue{
    int *arr;
    int size;
    int front,rear;
}cq;
int isfull(cq *q)
{
    return ((q->rear+1)%q->size==q->front);
}
int isempty(cq *q)
{
    return (q->front==-1);
}
void enqueue(cq *q,int data)
{
    if(isfull(q))
    {
        printf("queue overflow");
        return;
    }
    if(isempty(q))
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
int dequeue(cq *q)
{
    if(isempty(q))
    {
        printf("queue is empty!!");
        return -1;
    }
    int data=q->arr[q->front];
    if(q->rear==q->front)
    {
        q->rear=-1;
        q->front=-1;
    }
    else
    {
        q->front=(q->front+1)%q->size;
    }
    return data;
}
void display(cq *q)
{
    // Check if queue is empty
    if (isempty(q))
    {
        printf("The queue is empty!!\n");
        return;
    }

    printf("Queue elements: ");
    
    int i = q->front;

    // Loop until i reaches rear (inclusive)
    while (1)
    {
        printf("%d ", q->arr[i]);

        // Stop after printing rear
        if (i == q->rear)
            break;

        // Move to next index circularly
        i = (i + 1) % q->size;
    }
    
    printf("\n"); // Move to next line after display
}

int main()
{
    int data;
    cq q;
    q.front=-1;
    q.rear=-1;
    printf("Enter the size of the queue:");
    scanf("%d",&q.size);
    for(int i=0;i<q.size;i++)
    {
        printf("Enter the data:");
        scanf("%d",&data);
        enqueue(&q,data);
    }
    printf("displaying the element:");
    display(&q);    
    printf("element which dequeue:%d",data=dequeue(&q));
    enqueue(&q,data);
    printf("element which dequeue:%d",data=dequeue(&q));
    enqueue(&q,data);
    printf("element which dequeue:%d",data=dequeue(&q));
    enqueue(&q,data);
    printf("displaying the element:");
    display(&q);
    return 0;
}