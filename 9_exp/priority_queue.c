#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *start = NULL;
struct node *insert(struct node *);
struct node *delete(struct node *);
struct node *display(struct node *);
void main(){
    int choice;
    do
    {
        printf("\nRonit Satish Mehta 60009230207\n");
        printf("\t\t-------PRIORITY QUEUE OPERATIONS--------\n");
        printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            start = insert(start);
            break;
        case 2:
             start = delete(start);
             break;
        case 3:
             start = display(start);
             break;
        case 4:
            printf("\nExiting...");
            break;
        default:
           printf("\nInvalid choice");
            break;
        }
        /* code */
    } while (choice!=4);
    
}
struct node *insert(struct node *start){
    int val,pri;
    struct node *ptr,*p;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value and its priority:");
    scanf("%d %d",&val,&pri);
    ptr->data=val;
    ptr->priority=pri;
    if (start == NULL || pri< start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    else{
        p = start;
        while (p->next!=NULL&&p->next->priority<=pri)
        {
            p = p -> next;
        }
          ptr->next = p->next; 
        p->next = ptr;
    }
    return start;
}
struct node *delete(struct node *delete){
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nUnderflow");
    }
    else{
        ptr = start;
        printf("\nDeleted item is %d",ptr->data);
        start = start->next;
        free(ptr);
    }
    return start;
}
struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    if (start == NULL )
    {
        printf("\nQueue is Empty");
    }
    else
    {
        printf("\n Priority Queue is:");
        while (ptr!=NULL)
        {
            printf("\t%d[priority=%d]",ptr->data,ptr->priority);
            ptr=ptr->next;
        }
        
    }
     return start;

}