//An ATM cassette starts with a known number of Rs 500 notes. Withdrawal requests arrive one at a
//time until a 0 is entered.
//A request is served only if it is a multiple of 500 and enough notes remain. For a served request,
//print SERVED followed by the number of notes remaining after it. For a request that is not a multiple
//of 500, print NOT A MULTIPLE OF 500 and go on to the next request. For a request that cannot be
//met from the notes remaining, print CASSETTE EMPTY and stop the machine entirely, processing
//nothing further.
//At the end, print the total amount dispensed.
#include <stdio.h>
int main(void) {
    int notes;
    if (scanf("%d", &notes) != 1 || notes < 0) {
        return 1;
    }
    int total_dispensed = 0;
    while (1) {
        int request;
        if (scanf("%d", &request) != 1 || request < 0) {
            return 1;
        }
        if (request == 0) {
            break;
        }
        if (request % 500 != 0) {
            printf("NOT A MULTIPLE OF 500\n");
            continue;
        }
        int notes_needed = request / 500;
        if (notes_needed > notes) {
            printf("CASSETTE EMPTY\n");
            break;
        }
        notes -= notes_needed;
        total_dispensed += request;
        printf("SERVED %d\n", notes);
    }
    printf("TOTAL DISPENSED: %d\n", total_dispensed);
    return 0;
}   