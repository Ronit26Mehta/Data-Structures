#include<stdio.h>
void quick(int array[],int low,int high);
int partition(int array[],int low,int high);
void swap(int array[],int *i,int *j);
void main(){
    int array[100];
    int low;
    int high;
    int n;
    printf("Ronit Satish Mehta 60009230207\n");
    printf("\n Enter the array size:");
    scanf("%d",&n);
    printf("\nEnter the  of elements for an array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    
    printf("\nEnter lower bound :");
    scanf("%d",&low);
    printf("\n Enter higher bound:");
    scanf("%d",&high);
    quick(array,low,high);
    printf("\n the sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t",array[i] );
    }
    
}
void quick(int array[],int low,int high){
    int m;
    if (low<high)
    {
        m=partition(array,low,high);
        quick(array,low,m-1);
        quick(array,m+1,high);
    for (int i = 0; i < high+1; i++)
    {
        printf(" %d\t",array[i] );
    }

    }
    
}
int partition(int array[],int low ,int high){
    int pivot = array[low];
    int i = low;
    int j = high;/* code */
    while (i<=j ){
        while(array[i]<=pivot)
         i++;
        while (array[j]>pivot)
         j--;
        if (i<j)
        {
            swap(array,&i,&j);
        }
    
        
    }
        swap(array,&low,&j);
  
        
        return j;

}
void swap(int array[],int *i,int *j){
    int temp ;
    temp = array[*i];
    array[*i] = array[*j];
    array[*j]=temp;
}
