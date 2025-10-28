#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int front;
    int rear;
    int size;
    int *arr;
}queue;
void enqueue(queue *q,int data)
{
    if(q->rear==q->size-1)
    {
        printf("Queue overflow.");
        return;
    }
    if(q->front==-1)
    {
        q->front=0;
        q->rear=0;
    }
    else
    {
        q->rear=q->rear+1;
    }
    q->arr[q->rear]=data;
}
int dequeue(queue *q)
{
    if (q->front==-1)
    {
        printf("queue underflow.");
        return -1;
    }
    int val=q->arr[q->front++];
    if(q->front>q->rear)
    {
        q->front=q->rear=-1;
    }
    return val;
}
void genearate_binary(queue *q)
{
    int i=1,req;
    if(q->front==-1)
    enqueue(q,1);
    printf("\n%d\n",i);
    while(1)
    {
        req=dequeue(q);
        req=req*10;
         if(i>=q->size)
        break;
        enqueue(q,req);
        printf("%d\n",req);
        i++;
        req=req+1;
        if(i>=q->size)
        break;
        enqueue(q,req);
        printf("%d\n",req);
        i++;
    }
}
int main()
{
    int num;
    queue q;
    printf("please enter the no.of elements you want to generate:");
    scanf("%d",&num);
    q.size=num;
    q.front=-1;
    q.rear=-1;
    q.arr=(int *)malloc(sizeof(int)*num);
    printf("\ndisplaying the binary representation up to n-numbers:");
    genearate_binary(&q);
    return 0;
}