#include<stdio.h>
int main()
{
    int n,i,j;
    printf("please enter the number you want to store:");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("$");
        }
        printf("\n");
    }
}