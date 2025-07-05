#include<stdio.h>
#include<stdlib.h>
void bubblesort(int *,int );
void swap(int *,int ,int );
void display(int *,int );
int main()
{
    int *ptr=NULL;
    int n,i;
    printf("please enter the no.of elements you want to insert in the array:");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int));
    if(ptr==NULL)
    {
        printf("\nmemory allocation failed !!");
        exit(1);
    }
    printf("\nGiving input to the array element:");
    for (i=0;i<n;i++)
    {
        printf("\nplease enter the data to the %d position:",i);
        scanf("%d",(ptr+i));
    }
    printf("Displaying the array elements:\n");
    display(ptr,n);
    printf("\nsorting the array:\n");
    bubblesort(ptr,n);
    display(ptr,n);
}
void bubblesort(int *ptr,int n)
{
    int i,j,found;
    for(i=0;i<n;i++)
    {
        found=0;
        for(j=0;j<n;j++)
        {
            if(*(ptr+j)>*(ptr+j+1))
            {
                swap(ptr,j,j+1);
                found=1;
            }
        }
        if(found==0)
        break;
    }
}
void swap(int *ptr,int i,int min)
{
    int temp=*(ptr+i);
    *(ptr+i)=*(ptr+min);
    *(ptr+min)=temp;
}
void display(int *ptr,int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d\n",*(ptr+i));
}
