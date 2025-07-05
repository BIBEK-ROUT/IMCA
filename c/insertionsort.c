#include<stdio.h>
#include<stdlib.h>
void insertionsort(int *,int );
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
    insertionsort(ptr,n);
    display(ptr,n);
}
void insertionsort(int *ptr,int n)
{
    printf("the array is sorted:");
    int i,j,k;
    for(i=1;i<n;i++)
    {
        k=*(ptr+i);
        j=i-1;
        while(j>=0 && *(ptr+j)>k)
        {
            *(ptr+j+1)=*(ptr+j);
            j--;
        }
        *(ptr+j+1)=k;
    }
}
void swap(int *ptr,int k,int j)
{
    int temp=*(ptr+j);
    *(ptr+j)=*(ptr+k);
    *(ptr+k)=temp;
}
void display(int *ptr,int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d\n",*(ptr+i));
}