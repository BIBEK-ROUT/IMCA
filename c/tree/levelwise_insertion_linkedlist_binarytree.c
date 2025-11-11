#include<stdio.h>
#include<stdlib.h>
//Structure defined for Treenode and queue.
typedef struct Treenode
{
    int data;
    struct Treenode * left;
    struct Treenode *right ;
} Treenode;
typedef struct queue
{
    struct Treenode *items ;
    struct queue *next;
} queue;
//To  create node for the linkedlist based queue which is designed to track the tree nodes for level wise insertion.
queue* get_node(Treenode *address)
{
    queue *node1=NULL;
    node1=(queue *)malloc(sizeof(queue));
    if(node1==NULL)
    {
        printf("Memory allocation failed!!!");
        exit(1);
    }
    node1->items=address;
    node1->next=NULL;
    return node1;
}
void enqueue(Treenode *address,queue **front,queue **rear)
{
    queue * node=get_node(address);
    if(*front==NULL)
    {
        *front=*rear=node;
    }
    else
    {
        (*rear)->next=node;
        *rear=node;
    }
}
Treenode * dequeue(queue **front,queue **rear)
{
    queue *node;
    if(*front==NULL)
    {
        printf("queue underflow!!");
        return NULL;
    }
    node=*front;
    Treenode *item=node->items;
    *front=(*front)->next;
    if(*front==NULL)
    {
        *rear=NULL;
    }
    free(node);
    return item;
}
//For creating Treenode.
Treenode * create_node(int data)
{
    Treenode *node=NULL;
    node=(Treenode*)malloc(sizeof(Treenode));
    if(node==NULL)
    {
        printf("memory allocation failed!!!");
        exit(1);
    }
    node->data=data;
    node->left=node->right=NULL;
    return node;
}
//Create the tree node.
void create_Tree(int data,Treenode **root)
{
    char ch;
    queue *front=NULL,*rear=NULL;
    *root=create_node(data);
    enqueue(*root,&front,&rear);
    while(front!=NULL)
    {
        Treenode *current=dequeue(&front,&rear);
        printf("If you want to create a left child of %d press y:",current->data);
        scanf(" %c",&ch);
        if(ch=='y')
        {
            printf("please enter the left child:");
            scanf("%d",&data);
            current->left=create_node(data);
            enqueue(current->left,&front,&rear);
        }
        printf("If you want to create a right child of %d press y:",current->data);
        scanf(" %c",&ch);
        if(ch=='y')
        {
            printf("please enter the right child:");
            scanf("%d",&data);
            current->right=create_node(data);
            enqueue(current->right,&front,&rear);
        }
    }
}
//Accessing the Tree in preoder manner.
void preorder(Treenode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Treenode * root=NULL;
    int data;
    printf("please enter the root node:");
    scanf("%d",&data);
    create_Tree(data,&root);
    
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\n");
    return 0;
}