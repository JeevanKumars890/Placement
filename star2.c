#include <stdio.h>
int main(void ) {
    int n;
    if (scanf("%d",&n) !=1){
        return 1;

    }
int triayn=0;
 for (int row =1;row <=n ;row++){
    for(int s=0;s<n-row;s++){
        printf(" ");
    }
    for(int col=0;col<row;col++){
        if(col>1){
            printf(" ");
        }
        printf("%d",triayn);
        triayn++;
 }
 printf("\n");
 }
 printf("total number of triangle numbers is %d\n",triayn-1);
 return 0;
}