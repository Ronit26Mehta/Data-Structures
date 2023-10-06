#include<stdio.h>
int main() {
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
    for( int k=0;k<n;k++){
        printf("\n");
        printf("%d",a[k]);
    }
    insertionsort(a,n);
}
int insertionsort(int a[], int n){
    for(int i=1;i<n;i++){
         int t = a[i];
        int j = i -1;
        while(j>=0 && a[j]>t){
            a[j+1] =  a[j];
            j = j-1;

        }
        a[j+1]=t;
    }
    printf("elments after insertion sort");
    for( int k=0;k<n;k++){
        
        printf("\n");
        printf("%d",a[k]);
    }

}
