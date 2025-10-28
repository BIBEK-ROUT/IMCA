#include<stdio.h>
#define SIZE 30

char tree[SIZE];
void build_tree(int i,char ch)
{
    char opt;
    if(i!=-1)
    {
        tree[i]=ch;
        char node_char;
        printf("\n%c node has left child(y/n)? ",ch);
        getchar();
        scanf("%c",&opt);
        if(opt=='y' || opt=='Y')
        {
            printf("\nEnter the character for left child: ");
            getchar();
            scanf("%c",&node_char);
            build_tree(2*i+1,node_char);
        }
        /*else
        {
            build_tree(-1,'\0');
        }*/
        printf("\n%c node has right child(y/n)? ",ch);
        getchar();
        scanf("%c",&opt);
        if(opt=='y' || opt=='Y')
        {
            printf("\nEnter the character for right child: ");
            getchar();
            scanf("%c",&node_char);
            build_tree(2*i+2,node_char);
        }
        /*else
        {
            build_tree(-1,'\0');
        }*/
        
    }
}
int main()
{
    int j;
    char ch;
    printf("\nEnter the character for root node: ");
    scanf("%c",&ch);
    build_tree(0,ch);
    printf("\nThe Tree: \n");
    for(j=0;j<SIZE;j++)
    {
        if(tree[j]!='\0')
            printf("%d=%c\n",j,tree[j]);
    }
        
}