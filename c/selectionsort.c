#include<stdio.h>
#include<stdlib.h>
void selectionsort(int *,int );
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
    selectionsort(ptr,n);
    display(ptr,n);
}
void selectionsort(int *ptr,int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<=n;j++)
        {
            if(*(ptr+j)<*(ptr+min))
            min=j;
        }
        if(min!=i)
        {
            swap(ptr,i,min);
        }
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
