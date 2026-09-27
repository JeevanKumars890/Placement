//A ration shop reconciles its stock at the end of a period. For each item there is an opening
//quantity, an actual closing quantity, and a recorded issued quantity. The expected closing quantity
//for an item is its opening quantity less the quantity issued.
//Read N, then the N opening quantities, then the N closing quantities, then the N issued quantities.
//For every item where the actual closing does not equal the expected closing, print the item number
//and the signed discrepancy, which is the actual closing less the expected closing. Then print the
//number of mismatches and the total of the absolute discrepancies.
//If every item matches, print RECONCILED and nothing else. Items are numbered from 1.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter the number of items: ");
    scanf("%d", &N);

    int *opening = (int *)malloc(N * sizeof(int));
    int *closing = (int *)malloc(N * sizeof(int));
    int *issued = (int *)malloc(N * sizeof(int));

    printf("Enter the opening quantities:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &opening[i]);
    }

    printf("Enter the closing quantities:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &closing[i]);
    }

    printf("Enter the issued quantities:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &issued[i]);
    }

    int mismatches = 0;
    int totalDiscrepancy = 0;

    for (int i = 0; i < N; i++) {
        int expectedClosing = opening[i] - issued[i];
        if (closing[i] != expectedClosing) {
            int discrepancy = closing[i] - expectedClosing;
            printf("Item %d: Discrepancy %d\n", i + 1, discrepancy);
            mismatches++;
            totalDiscrepancy += abs(discrepancy);
        }
    }

    if (mismatches == 0) {
        printf("RECONCILED\n");
    } else {
        printf("Number of mismatches: %d\n", mismatches);
        printf("Total absolute discrepancies: %d\n", totalDiscrepancy);
    }

    free(opening);
    free(closing);
    free(issued);

    return 0;
}   