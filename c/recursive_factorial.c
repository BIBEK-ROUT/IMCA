#include<stdio.h>
long int factorial(int data)
{
    if(data==1)
    {
        return 1;
    }
    int f=factorial(data-1);
    f=data*f;
    return f;
}
int main()
{
    int n;
    printf("please entr the number:");
    scanf("%d",&n);
    printf("%ld",factorial(n));
    return 0;
}