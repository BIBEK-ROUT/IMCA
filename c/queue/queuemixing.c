#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int f;
    int r;
    int *arr;
    int size;
}queue;
int isfull(queue *q)
{
    return (q->r+1)%q->size==q->f;
}
int isempty(queue *q)
{
    return q->f==-1;
}
void enqueue(int data, queue *q)
{
    if (isfull(q))
    {
        printf("Queue overflow!!\n");
        return;
    }
    if (isempty(q))
    {
        q->f = 0;
        q->r = 0;
    }
    else
    {
        q->r = (q->r + 1) % q->size;
    }
    q->arr[q->r] = data;
}

int dequeue(queue *q)
{
    if (isempty(q))
    {
        printf("The queue is empty!!\n");
        return -1;
    }
    int data = q->arr[q->f];
    if (q->r == q->f)
    {
        q->f = -1;
        q->r = -1;
    }
    else
    {
        q->f = (q->f + 1) % q->size;
    }
    return data;
}
void shuffle(queue *q,int n,int n1)
{
    int data1,data2;
    if(n>=1)
    {
        data1=dequeue(q);
       if(n>1)
        {
            shuffle(q,n-1,n1);
        }
    }
    if(n==1)
    {
    data2=dequeue(q);
    enqueue(data1,q);
    enqueue(data2,q);
    }
}
void display1(queue *q)
{
    for(int i=0;i<q->size;i++)
    {
        printf("%d",q->arr[i]);
    }
}
void display(queue *q)
{
    if(isempty(q))
    {
        printf("The queue is empty!!");
        return;
    }
    int i=q->f;
    printf("The array elements are:");
    while(1)
    {
        printf("%d",q->arr[i]);
        if(i==q->r)
        break;
        i=(i+1)%q->size;
    }
    printf("\n");
}
int main()
{   
    queue q;
    int data;
    printf("Please enter the size of the queue:");    
    scanf("%d",&q.size);
    q.f=-1;
    q.r=-1;
    q.arr=(int *)malloc(sizeof(int)*q.size);
    for(int i=0;i<q.size;i++)
    {
        printf("please enter the data:");
        scanf("%d",&data);
        enqueue(data,&q);
    }
    display(&q);
    shuffle(&q,q.size/2,1);
    display1(&q);
    return 0;
}