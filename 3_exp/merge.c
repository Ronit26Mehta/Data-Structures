#include<stdio.h>
void mergesort(int array[],int l,int h);
void merge(int array[],int l,int mid,int h);
void main(){
    int array[100];
    int n;
    int l;
    int h;
    printf("Ronit Satish Mehta 60009230207 \n");
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter %d elements in an array:",n );
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the lower bound:");
    scanf("%d",&l);
    printf("Enter the upper bound:");
    scanf("%d",&h);
    mergesort(array,l,h);    
}
void mergesort(int array[],int l,int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
    mergesort(array,l,mid);
    mergesort(array,mid+1,h);
    merge(array,l,mid,h);
    }
    
}
void merge(int array[],int l,int mid,int h){
int n1;
int n2;
n1 = mid - l + 1;
n2 = h - mid;
int L[n1+1],R[n2+1];
for(int i = 0;i<n1;i++){
    L[i] = array[l+i];

}
for (int  i = 0; i < n2; i++)
{
    R[i] = array[mid+1+i];
}
L[n1]=99999;
R[n2]=99999;
int i = 0;
int j = 0;
for (int k = l; k <= h; k ++){
    if(L[i]<=R[j]){
        array[k] = L[i];
        i = i + 1;
    }
    else{
        array[k] = R[j];
        j=j+1;
    }


}
printf("\nSorted Array:\n");
for (int i = l; i <=  h; i++)
{
   
    printf("%d",array[i]);
    printf("\t");
}


}