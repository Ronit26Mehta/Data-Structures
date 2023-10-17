#include<stdio.h>
#define size 10
void insert();
void display();
void search();
 int hash_table[size]={0};
    int n;
int size1;
void main(){
   
    int choice;
    printf("Ronit Satish Mehta 60009230207\n");
    printf("\n Enter the size for the hash Second:");
    scanf("%d",&size1);
    do{
     printf("\n\t\t\t HASH ALLOCATION \n");
     printf("\nEnter the choice for operations:\n");
     printf("\n1.insert\n2.display\n3.search\n4.exit");
     scanf("%d",&choice);
     switch(choice){
        case 1:
        insert();
        break;
        case 2:
        display();
        break;
        case 3:
        search();
        break;
        case 4:
        printf("\nexiting....");
        break;
        default:
        printf("\nInvalid Choice!!!");
        break;

     }

    }while(choice!=4);
    


}
void insert(){
    int key,index,i,flag =0,hkey,hkey1;
    printf("\nEnter the value for hash key :");
    scanf("%d",&key);
    hkey = key% size;
    hkey1 = key % size1;
    for (int i = 0; i < size; i++)
    {
        index = (hkey + i * hkey1) % size;
        if (hash_table[index] == 0)
        {
            hash_table[index] = key;
            break;
        }
    }
    if (i == size)
    {
        printf("\n elemenets cannot be inserted.\n ");
    }
    
}
void display(){
    int i;
    printf("\n The hash Table is as follows");
    printf("\n Index \t value \n");
    for (int i = 0; i < size; i++)
    {
        printf("\n");
        printf("%d\t %d\t",i,hash_table[i]);
    }
}
void search(){
    int key,index,i,flag = 0,hkey;
    printf("\n Enter Search Element:");
    scanf("%d",&key);
    hkey = key % size;
    for (int i = 0; i < size; i++)
    {
        index = (hkey+i)%size;
        if (hash_table[index] == key)
        {
            printf("\nthe value was found at this index %d",index);
            break;
        }
        

    }
    if (size == i)
    {
        printf("\n value not found\n");
    }
    
    
}
