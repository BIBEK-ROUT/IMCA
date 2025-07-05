#include<stdio.h>
int main()
{
    int num,i,j;
    printf("please enter the no.of lines you want:");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=i;j<=num+i-1;j++)
        {
            printf("%4d",j);
        }
        printf("\n");
    }
    return 0;
}