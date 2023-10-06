#include<stdio.h>
void tower(int,char,char,char);
 int main(){
    int num;
    printf("Ronit Satish Mehta SAP ID:- 60009230207 \n");
    printf("Enter the number of the disks: \n");
    scanf("%d", &num);
    printf("the number of the moves invovled are: \n");
    tower(num ,'A','C','B');
    return 0;
}
void tower(int num,char frompeg,char topeg,char auxpeg){
 if(num ==1){
 printf("\n the disk is moved from %c to %c",frompeg,topeg);
 return;
}
    tower(num-1,frompeg,auxpeg,topeg);
    printf("\n move disk %d is moved from %c to %c",num,frompeg,topeg);
    tower(num-1,auxpeg,topeg,frompeg);

}
