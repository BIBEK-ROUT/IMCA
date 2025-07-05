#include<stdio.h>
int main()
{
    int num,i,j;
    printf("please enter the number of lines you want to enter:");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=(num+1)/2;j++)
        printf("%d %d ",j,i);
        printf("\n");
    }
}