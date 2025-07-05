#include<stdio.h>
    int main()
    {
        int num,i,j;
        printf("please enter the no.of lines you want:");
        scanf("%d",&num);
        for (i=1;i<=num;i++)
        {
            for(j=i;j<=(num*num)-(num-i);j+=num)
            {
                printf("%4d",j);
            }
            printf("\n");
        }
    }