#include<stdio.h>
    int main()
    {
        int num,i,j,m,k,increment,num1;
        printf("please enter the no.of lines you want:");
        scanf("%d",&num);
        for(i=num;i>=1;i--)        
        {
            increment=2*num;
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
