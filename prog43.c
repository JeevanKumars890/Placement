//Given a signed 32-bit integer x, print true when x reads the same forwards and backwards, and
//false otherwise.
#include <stdio.h>
int main(){
    int x;
    scanf("%d",&x);
    int original = x;
    int reversed = 0;
    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    
    if (original == reversed) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}