#include<stdio.h>
int main()
{
    int num,i,j,num1=1,num2;
    printf("please enter the no.of lines you want:");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        if(i!=1)
        num1=num1+i;
        num2=num1;
        for(j=1;j<=i;j++)
        {
            printf("%4d",num2);
            num2--;
        }
        printf("\n");
    }
}