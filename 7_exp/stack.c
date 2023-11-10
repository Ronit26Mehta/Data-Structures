#include<stdio.h>
#define max 10
int stack[max],top=-1;
void push(int stack[],int val);
int pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);
void main(){
    int val,choice;
    do{
        printf("\nstack operation\n");
        printf("1.press 1 for push\n2.press 2 for pop\n3.press 3 for peek\n4.press 4 for display\n5.press 5 for exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Value to push:");
            scanf("%d",&val);
            push(stack,val);
            break;
        case 2:
            val = pop(stack);
            if (val == -1)
            {
                printf("stack empty");
            }
            else{
                printf("the value poped is : %d",val);
            }
            break;
        case 3:
           val = peek(stack);
           if (val == -1)
           {
             printf("stack is empty");
           }
           else{
            printf("peeked element is : %d",val);
           }
           break;
        case 4:
           display(stack);
           break;
        default:
            printf("Enter valid choice");
            break;
        }
    }while (choice!=5);
}
void push(int stack[],int val){
   if (top == max -1)
   {
    printf("\nstack overflow");
   }
   else{
    top ++;
    stack[top] = val;
   }
   
}
int pop(int stack[])
{
    if (top == -1)
    {
        printf("\nstack underflow");
    }
    else 
    {
        return stack[top--];
    }   
}
int peek(int stack[]){
    if (top == -1)
    {
       printf("\nstack  underflow");
    }
    else{
        return stack[top];
    }
}
void display(int stack[]){
    if (top == -1)
    {
        printf("\nstack empty");
    }
    else{
        printf("\nThe stack is displayed here:\n");
        for (int i = top; i >=0; i--)
        {
            printf("%d\n",stack[i]);
        }
        
    }
    
}