#include<stdio.h>
#include<stdlib.h>
char *stack;
int size;
int top = -1;
void put(char data)
{
    if (top == size - 1) {
        printf("Stack overflow!!\n");
        return;
    }
    stack[++top] = data;
}
void pop()
{
    if (top == -1) {
        printf("Stack underflow!!\n");
        return;
    }
    top--;
}
int check()
{
    if (top == -1) {
        printf("Stack is empty!!\n");
        return 0;
    }
    int *req=(int *)malloc(size*sizeof(int)),count=-1;
    for(int i=0;i<size;i++)
    {
        char ch =stack[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            req[++count] = ch; // Push opening brackets onto the stack
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            char last=req[count--]; // Pop the last opening bracket
            if(ch==')' && last != '('|| ch=='}' && last != '{' || ch==']' && last != '[')
            {
                return 1;
            }
        }
    }
    return 0;
}
void display()
{
    if (top == -1) {
        printf("Stack is empty!!\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = 0; i <= top; i++) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}
int main()
{
    char ch;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    stack = (char *)malloc(size * sizeof(char));
    
    printf("Enter the elements of the stack:\n");
    for(int i = 0; i < size; i++)
    {
        printf("enter the parentheses: ");
        scanf(" %c", &ch);
        put(ch);
    }
    if(check()==1)
    {
        printf("Not Balanced \n");
    }
    else
    {
        printf("Balanced \n");
    }
}