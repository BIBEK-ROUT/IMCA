#include<stdio.h>
#include<stdlib.h>

// Global variable to hold the number of disks (also used as stack size)
int size;

// Define the stack structure
typedef struct stack{
    int *arr;
    int top;
    char name;  // To identify the stack (A, B, or C)
}stack;

// Function to initialize a stack with a given name
void intialize(stack *s,char name)
{
    s->name=name;
    s->top=-1;
    s->arr=(int*)malloc(sizeof(int)*size);
}

// Function to push data onto the stack
void push(stack *s,int data)
{
    if(s->top==size-1)
    {
        printf("stack overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top]=data;
}

// Function to pop data from the stack
int pop(stack *s)
{
    if(s->top==-1)
    {
        printf("stack underflow\n");
        return -1;
    }
    int data=s->arr[s->top];
    s->top--;
    return data;
}

// Function to display a stack's contents
void display(stack *s)
{
    if(s->top==-1)
    {
        printf("stack is empty\n");
        return;
    }
    printf("Stack %c: ", s->name);
    for(int i=s->top; i>=0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Function to move top disk from source stack to destination stack
void movedisk(stack *s,stack *d)
{
    // 🌟 CHANGE MADE HERE: Added step printing to show disk movement
    int disk = pop(s);                      // Pop from source
    d->arr[++d->top] = disk;                // Push to destination
    printf("Move disk %d from %c to %c\n",  // Print the move
           disk, s->name, d->name);
    return;
}

// Recursive function to solve Tower of Hanoi
void hanoi(int n,stack *s,stack *a,stack *d)
{
    if(n==1)
    {
        movedisk(s,d);
        return;
    }
    hanoi(n-1,s,d,a);  // Move n-1 disks to auxiliary
    movedisk(s,d);     // Move remaining disk to destination
    hanoi(n-1,a,s,d);  // Move n-1 disks from auxiliary to destination
    return;
}

// Main function
int main()
{
    stack A,B,C;
    int data;

    // Input number of disks (also determines the stack size)
    printf("Enter the no.of disks:");
    scanf("%d",&size);

    // Initialize all three stacks
    intialize(&A,'A');
    intialize(&B,'B');
    intialize(&C,'C');

    // Input disk values and push them to stack A
    for(int i=0;i<size;i++)
    {
        printf("Enter the data:");
        scanf("%d",&data);
        push(&A,data);
    }

    // Display initial stack state
    printf("Initial stacks:\n");
    display(&A);

    // Solve Tower of Hanoi
    hanoi(size,&A,&B,&C);

    // Display final state of stack C
    printf("Stacks after moving disks:\n");
    display(&C);

    return 0;
}
