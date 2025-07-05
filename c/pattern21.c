#include<stdio.h>
int main()
{
    int num,i,j;
    printf("please enter the no.of lines you want:");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num;j++)
        {
            if(i%2!=0 && j%2!=0)
            {
                printf("0");
            }
            else if(i%2!=0 && j%2==0)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
}