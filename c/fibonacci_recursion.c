#include<stdio.h>
int search(int n,int a,int b)
{
    int sum;
    if(n==0)
    return b;
    int s;
    sum=a+b;
    a=b;
    b=sum;
    n=n-1;
    s=search(n,a,b);
     return s;
}
int main()
{
    int n,a=0,b=1;
    printf("Enter the number:");
    scanf("%d",&n);
    if(n==1)
    {
        printf("The nth number of the series is:0");
    }
    else if(n==2)
    {
        printf("The nth number of the series is:1");
    }
    else
        printf("%d",search(n-2,a,b));
    return 0;
}