#include <stdio.h>
int main() {
    int n;
    if (scanf("%d",&n)!=1){
        return 1;

    }
    for(int row =1 ; row <=n ;row ++){
        for (int s=1 ; s <= n-row ; s++){
            printf(" ");
        }
        for (int c=1 ; c <= 2*row-1 ; c++){
            printf("*");
        }
        printf("\n"); 
    }
    for(int row = n-1 ; row >= 1 ;row --){
        for (int s=1 ; s <= n-row ; s++){
            printf(" ");
        }
        for (int c=1 ; c <= 2*row-1 ; c++){
            printf("*");
        }
        printf("\n"); 
    }
    return 0;
}