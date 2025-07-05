#include<stdio.h>
#include<stdlib.h>
int  binarysearch(int *,int ,int );
void swap(int *,int ,int );
void display(int *,int );
void bubblesort(int *,int);
int main()
{
    int *ptr=NULL;
    int n,i,num,mid;
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
    printf("\nplease enter the data element you want to search:");
    scanf("%d",&num);
    printf("\n searching the element in the list:\n");
    bubblesort(ptr,n);
    mid=binarysearch(ptr,0,n-1);
    while(mid<n-1||mid>=0)
    {
        if(*(ptr+mid)==num)
        {
            printf("the element is found at %d position",mid);
            return 0;
        }
        else if(*(ptr+mid)>num)
        mid=binarysearch(ptr,0,mid);
        else if(*(ptr+mid)<num)
        mid=binarysearch(ptr,mid+1,n-1);
       
    }
    if(mid>n-1)
    {
        printf("The element is not found!!");
    }
    
}
void swap(int *ptr,int i,int min)
{
    int temp=*(ptr+i);
    *(ptr+i)=*(ptr+min);
    *(ptr+min)=temp;
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
int binarysearch(int *ptr,int low,int high)
{
   // if(low>high)
   // return -1;
  //  else
    {
    int mid=(low+high)/2;
    return mid;
    }
}
void display(int *ptr,int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d\n",*(ptr+i));
}
