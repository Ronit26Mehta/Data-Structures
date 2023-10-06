#include<stdio.h>

int main(){
   int a[100];
    int n;
    int x;
    int i;
    printf("Ronit Satish Mehta SAP ID:-60009230207");
    printf("\n Enter the numbers of the elment to be in an array");
    scanf("%d",&n);
    printf("\n start entering the number of the elments" );
    for(i=0;i < n;i++){
        scanf("%d", &a[i]);
    }
    printf("Before \n");
    for( int k=0;k<n;k++){
        printf("\n");
        printf("%d",a[k]);
    }
    selectionsort(a,n);

}
int selectionsort( int a[] , int n)
{
for(int i = 0;i<n-1; i++){
    int min = i;
    for(int j = i+1; j< n; j++){
        if(a[j]<a[min]){
            min = j ;
        }
       int t = a[i];
       a[i] = a[min];
       a[min] = t;
    }

}
printf("\nafter \n");
   for( int k=0;k<n;k++){
        printf("\n");
        printf("%d ", a[k]);
    }
}