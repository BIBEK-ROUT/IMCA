#include<stdio.h>
int main()
{
    int num,i,j,num1;
    printf("please enter the no.of lines you want:");
    scanf("%d",&num);
    for(i=num;i>=1;i--)
    {
        num1=i;
        for(j=1;j<=num;j++)
        {
            printf("%4c",num1+64);
            num1=num1+num;
        }
        printf("\n");
    }
}