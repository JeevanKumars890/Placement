//A chit fund group of N members runs for N months. Every member pays a fixed monthly
//subscription S. In month m, one member, member m, wins the pot and receives it, while every
//other member pays their subscription.
//The pot is N times S, less a foreman commission of 5 percent.
//Print the pot, then an N by N table of cash movements. Row m shows, for each member in turn,
//either the amount that member paid, as a positive number, or the pot they received, as a negative
//number. Each row ends with its own total. After the table, print a line of column totals, one per
//member.
#include <stdio.h>
int main(){
    int n,s;
    if(scanf("%d %d",&n,&s)!=2){
        return 1;
    }
    int pot = n*s - (n*s*5)/100;
    printf("%d\n",pot);
    int total[n];
    for(int i=0;i<n;i++){
        total[i]=0;
    }
    for(int i=0;i<n;i++){
        int rowtotal=0;
        for(int j=0;j<n;j++){
            if(i==j){       
                printf("%d ",-pot);
                rowtotal+=-pot;
                total[j]+=-pot;
            }
            else{
                printf("%d ",s);
                rowtotal+=s;
                total[j]+=s;
            }
        }
        printf("%d\n",rowtotal);
    }
    printf("Column totals: ");
    for(int i=0;i<n;i++){
        printf("%d ",total[i]);
    }
    printf("\n");               
        
    return 0; 
}