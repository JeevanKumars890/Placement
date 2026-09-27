//A milk collection tanker has C compartments with individual remaining capacities, and there are N
//village collections with given volumes, to be loaded in collection order.
//Write int packRoute(int caps[], int c, int vols[], int n, int *spilledOut, int
//*lastVillageOut).
//Each collection goes into the first compartment with enough remaining space, and that
//compartment's remaining capacity is reduced in place. A collection that fits nowhere is spilled and
//its volume is added to the spilled total through the first out-parameter. The index of the last
//successfully loaded village, counting villages from 1, is reported through the second out-
//parameter, and is 0 when nothing was loaded. The function returns the number of collections
//successfully loaded.
//In main, read the compartments and the villages, call the function, and print the return value, both
//out-parameters, and the final remaining capacity of every compartment.
#include <stdio.h>
int packRoute(int caps[], int c, int vols[], int n, int *spilledOut, int *lastVillageOut) {
    *spilledOut = 0;
    *lastVillageOut = 0;
    int loadedCount = 0;
    for (int i = 0; i < n; i++) {
        int volume = vols[i];
        int loaded = 0;
        for (int j = 0; j < c; j++) {
            if (caps[j] >= volume) {
                caps[j] -= volume;
                loaded = 1;
                loadedCount++;
                *lastVillageOut = i + 1; // Villages are counted from 1
                break;
            }
        }
        if (!loaded) {      
            *spilledOut += volume;
        }
    }
    return loadedCount;
}
int main() {
    int c, n;
    printf("Enter number of compartments: ");
    scanf("%d", &c);
    int caps[c];
    printf("Enter remaining capacities of compartments: ");
    for (int i = 0; i < c; i++) {
        scanf("%d", &caps[i]);
    }
    printf("Enter number of villages: ");
    scanf("%d", &n);
    int vols[n];
    printf("Enter volumes of village collections: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vols[i]);
    }
    int spilledOut, lastVillageOut;
    int loadedCount = packRoute(caps, c, vols, n, &spilledOut, &lastVillageOut);
    printf("Number of collections successfully loaded: %d\n", loadedCount);
    printf("Total spilled volume: %d\n", spilledOut);
    printf("Last successfully loaded village index: %d\n", lastVillageOut);
    printf("Final remaining capacities of compartments: ");
    for (int i = 0; i < c; i++) {
        printf("%d ", caps[i]);
    }
    printf("\n");
    return 0;
}
