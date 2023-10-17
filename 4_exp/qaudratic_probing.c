#include<stdio.h>
#define size 10
void insert();
void search();
void display();
int hash_table[size]={0};
int n;
int c1,c2;
void main(){
    int choice;
    printf("\nRonit Satish Mehta 60009230207");
    printf("\n Enter Qaudratic Equivalent for operations:");
    printf("\n Enter C1 :");
    scanf("%d",&c1);
    printf("\n Enter C2 :");
    scanf("%d",&c2);
    do
    {
    printf("\n HASHING ALLOCATION");
    printf("\n1.Insert\n2.search\n3.display\n4.exit");
    printf("\n Enter the choice for operations:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        insert();
        break;
    case 2:
         search();
         break;
    case 3:
        display();
        break;
    case 4:
      printf("Exiting...");
       break;
    default:
        printf("\nInvalid Choice");
        break;
    }
    } while (choice!=4);
}
void insert(){
    int key,index,i,flag =0,hkey;
    printf("\n Enter Hash Key:");
    scanf("%d",&key);
    hkey = key % size;
    for ( i = 0; i < size; i++)
    {
        index = (hkey +  c1*i + c2*i )% size;
        if (hash_table[index] == 0)
        {
            hash_table[index] = key;
            break;
        }
        
    }
    if (i ==  size)
    {
        printf("\n Error:\nThe Hash Table is full\n or \nElement cannot be inserted");
    }
}
void search(){
 int key,index,i,flag =0,hkey;
 printf("\nEnter the Element to be searched:");
 scanf("%d",&key);
 hkey = key % size;
 for ( i = 0; i < size; i++)
 {
    index = (hkey + c1*i + c2*i) % size;
    if (hash_table[index] == key)
    {
        printf("\n The Element was found at %d",index);
        break;
    }
 }
 if (i == size)
 {
    printf("\n Error: \n Element Not found");
 }
}
void display(){
    int i;
    printf("\n The Hash Table:\n");
    printf("\n Index \t value \n");
    for ( i = 0; i < size; i++)
    {
        printf("\n %d\t%d",i,hash_table[i]);
    }
    
}