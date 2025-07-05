#include<stdio.h>
int main()
{
    int num,i,j;
    printf("please enter the no.of lines you want:");
    scanf("%d",&num);
    for(i=1;i<=num+num-1;i+=2)
    {
        for(j=i;j<=num+num-2+i;j+=2)
        {
            printf("%4d",j);
        }
        printf("\n");
    }
}