#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) 
{
    if (top >= MAX - 1) 
    {
        printf("Stack Overflow\n");
    } 
    else 
    {
        stack[++top] = val; 
    }
}

int pop() 
{
    if (top < 0) 
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else 
    {
        return stack[top--]; 
    }
}

int main() 
{
    push(10);
    push(20);
    
    printf("Popped: %d\n", pop()); 
    printf("Popped: %d\n", pop());
    
    return 0;
}