#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define MAX 100
char *stack,infix[MAX],postfix[MAX];
int size=MAX;
int top=-1;
void push(char data)
{
    if(top==size-1)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top]=data;
}
int pop()
{
    if(top==-1)
    {
        printf("stack underflow!!");
        exit (1);
    }
    return stack[top--];
}
int isempty()
{
    return top==-1;
}

int precedence(char symbol)
{
    switch(symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
int inftopos()
{
    int i,j=0;
    char symbol,next;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next=pop())!= '(')
                {
                    postfix[j++]=next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isempty() && precedence(stack[top]) >= precedence(symbol))
                {
                    postfix[j++]=pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++]=symbol;
                break;
        }
    }
    while(!isempty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("Postfix expression is: ");
    for(i=0; i<j; i++)
    {
        printf("%c", postfix[i]);
    }
}
int main()
{
    stack=(char *)malloc(sizeof(char)*size);
    if(stack == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the infix expression:");
    gets(infix);
    inftopos();
    free(stack);
    return 0;
}