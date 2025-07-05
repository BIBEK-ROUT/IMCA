#include<stdio.h>
    int main()
    {
        int num,i,j,increment,m,k;
        printf("please enter the no.of lines you want:");
        scanf("%d",&num);
        for (i=1;i<=num;i++)
        {
            increment=num*2;
            k=i;
            m=increment-i+1;
            for(j=1;j<=num;j++)
            {
               
                if(j%2!=0)
                {
                    printf("%4d",k);
                    k+=increment;
                }
                else
                {
                    printf("%4d",m);
                    m+=increment;
                }
            }
            printf("\n");
        }
    }