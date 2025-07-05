#include<stdio.h>
    int main()
    {
        int num,j,i;
        printf("please enter the number of lines you want:");
        scanf("%d",&num);
        for(i=1;i<=num;i++)
        {
            for(j=i;j<=i*num;j+=i)
            {
                printf("  %d   ",j);
            }
            printf("\n");
        }
    }