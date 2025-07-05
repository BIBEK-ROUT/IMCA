#include<stdio.h>
#include<stdlib.h>
 struct{
    int *queue;
    int size;
    int f,r;
}q;
void enqueue(int data)
{
    if(q.r==q.size-1)
    {
        printf("queue overflow!!");
        return;
    }
    q.queue[++q.r]=data;
}
int dequeue()
{
    if(q.f==q.size-1)
    {
        printf("queue underflow!!");
        exit (1);
    }
    if(q.f==q.r)
    {
        q.f=-1;
        q.r=-1;
        return -1; // Queue is now empty
    }
    return q.queue[++q.f];
}
void display()
{
    if(q.r==-1)
    {
        printf("stack is empty!!");
        exit (1);
    }
    for(int i=q.f+1;i<=q.r;i++)
    {
        printf("%d",q.queue[i]);
    }
}
int main()
{
    int data;
    printf("Enter the size of the array:");
    scanf("%d",&q.size);
    q.queue=(int *)malloc(sizeof(int)*q.size);
    if(q.queue==NULL)
    {
        printf("Memory allocation failed!!");
        return 1;
    }
    q.f=-1;
    q.r=-1;
    for(int i=0;i<q.size;i++)
    {
        printf("Enter the data:");
        scanf("%d",&data);
        enqueue(data);
    }
    printf("The queue is:");
    display();
    printf("\n");
    dequeue();
    dequeue();
    printf("\nAfter dequeue the queue is:");
    display();
    return 0;
}