#include<stdio.h>
int main()
{
    int num,i,j,num1=1,k,num2,c;
    printf("please enter the no.of lines you want:");
    scanf("%d",&num);
    k=num;
    for(i=num;i>=1;i--)
    {
        num2=num1;
        c=i;
        for(j=num;j>=i;j--)
        {
            printf("%4d",num2);
            num2=num2-c;
            c++;
        }
        num1=num1+i;
        printf("\n");
    }
}