//A poultry farm records its egg collection for N days. Read N, then read the N daily counts, and
//report the total collection, the average per day as a decimal, and the number of days on which
//collection was above the average.
//Input format note. Because this block has no way to remember a list of values, the program
//reads the N daily counts, then reads the same N counts a second time. The repeat is required by
//the input format. It is not a mistake.
#include <stdio.h>
int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }
    int total = 0;
    for (int i = 0; i < n; i++) {
        int count;
        if (scanf("%d", &count) != 1 || count < 0)      {
            return 1;
        }
        total += count;
    }
    double average = (double)total / n;
    int above_average_count = 0;
    for (int i = 0; i < n; i++) {
        int count;
        if (scanf("%d", &count) != 1 || count < 0) {
            return 1;
        }
        if (count > average) {          
            above_average_count++;
        }
    }
    printf("%d\n", total);
    printf("%.2f\n", average);
    printf("%d\n", above_average_count);
    return 0;
}       