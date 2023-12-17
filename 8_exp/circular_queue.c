#include<stdio.h>
#define max 30
int queue[max];
int front = -1;
int rear = -1;
void insert();
int delete();
void display();
int peek();
void main(){
    int choice,val;
    do
    {
        printf("\n\t\t--------CIRCULAR QUEUE OPERATIONS-------\n");
        printf("\n1.Insert\n2.delete\n3.peekn4.display\n5.exit\n");
        printf("\nEnter Suitable choice for operations:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete();
            if (val != -1)
            {
                printf("\nThe number deleted is %d",&val);
            }
            break;
        case 3:
             val = peek();
             if (val  != -1)
             {
                printf("\nThe first value in the queue is:%d",val);
             }
            break;
        case 4:
             display();
             break;
        case 5:
             printf("\nExiting...");
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice != 5);
    
}
void insert(){
    int num;
    printf("\nEnter no. you want to insert in the queue:");
    scanf("%d",&num);
    if (front == 0 && rear == max-1)
    {
        printf("\nQUEUE OVERFLOW");
    }
    else if (front == -1 && rear == -1)
    {
        front=rear=0;
        queue[rear]=num;
    }
    else if(rear == max-1 && front !=0){
        rear= 0;
        queue[rear]= num;
    }
    else{
        rear++;
        queue[rear]=num;
    }
}
int delete(){
    int val;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue Underflow");
        return -1;
    }
    val = queue[front];
    if (front == rear)
    {
        front=rear=-1;
    }
    else{
        if (front == max-1)
        {
            front = 0;
        }
        else{
            front++;
        }
        
    }
    return val;
}
int peek(){
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty\n");
        return -1;
    }
    else{
        return queue[front];
    }
    
}
void display(){
    int i;
    printf("\n");
    if (front == -1 && rear == -1)
    {
        printf("\nQUEUE is empty\n");
    }
    else{
        if (front<rear)
        {
            for (int i =front; i <=rear ; i++)
            {
                printf("\t %d",queue[i]);
            }
        }
        else{
            for (int i = front; i < max; i++)
            {
                printf("\t %d",queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("\t %d",queue[i]);
            }
            
        }
        
    }
}