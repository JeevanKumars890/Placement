//A fruit grading line weighs each item once and needs three answers from that single pass: the
//minimum weight seen, the maximum weight seen, and how many items fall outside the accepted
//range of 80 to 200 grams inclusive.
//A C function returns exactly one value, so write void gradeStats(int weights[], int n, int
//*minOut, int *maxOut, int *rejectCount) which fills all three results through pointers.
//In main, read n and the n weights, declare the three result variables, pass their addresses, and
//print the three results.
#include <stdio.h>

void gradeStats(int weights[], int n, int *minOut, int *maxOut, int *rejectCount) {
    *minOut = weights[0];
    *maxOut = weights[0];
    *rejectCount = 0;

    for (int i = 1; i < n; i++) {
        if (weights[i] < *minOut) {
            *minOut = weights[i];
        }
        if (weights[i] > *maxOut) {
            *maxOut = weights[i];
        }
        if (weights[i] < 80 || weights[i] > 200) {
            (*rejectCount)++;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n];
    printf("Enter the weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int minWeight, maxWeight, rejectCount;
    gradeStats(weights, n, &minWeight, &maxWeight, &rejectCount);

    printf("Minimum weight: %d\n", minWeight);
    printf("Maximum weight: %d\n", maxWeight);
    printf("Number of rejected items: %d\n", rejectCount);

    return 0;
}