#include<stdio.h>
int min(int x,int y);
int fibonacci_search(int arr[],int x,int n);
void main(){
    int arr[100];
    int n;
    int val;
    int index;
    printf("\nEnter the size of the array:");
    scanf("%d",&n);
    printf("\nstart entering the %d number of elements.",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the value to be searched:");
    scanf("%d",&val);
    printf("\nthe array to be searched for the value is:");
    for (int i = 0; i < n; i++)
    {
        printf("\t %d",arr[i]);
    }

    index = fibonacci_search(arr,val,n);
    if (index>=0)

    {
        printf("\nthe value %d was found at %d index.",val,index);
    }
    else
    {
        printf("\nthe value %d was not found",val);
    }
}
int min(int x,int y){
    return(x<=y)?x:y;
}
int fibonacci_search(int arr[],int x,int n){
    int fibnm2 = 0;
    int fibm1 = 1;
    int fib = fibm1 + fibnm2;
    while (fib<n)
    {
        fibnm2 = fibm1;
        fibm1 = fib;
        fib = fibnm2 + fibm1;
    }
    int offset = -1;
    while (fib>1)
    {
        int i = min(offset+fibnm2,n-1);
        if (arr[i]<x)
        {
            fib = fibm1;
            fibm1 = fibnm2;
            fibnm2 = fib - fibm1;
            offset = i;
        }
        else if (arr[i]>x)
        {
            fib = fibnm2;
            fibm1 = fibm1 - fibnm2;
            fibnm2 = fib - fibm1;

        }
        else 
        {
            return i;
        }
    }
    if (fibm1 && arr[offset+1]==x)
    {
        return offset+1;
    }
    return -1;   
    
}
