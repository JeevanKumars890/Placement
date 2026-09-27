//A truck carries a maximum of 240 cement bags per trip. Consignments arrive one at a time and
//are loaded whole and in order: keep adding consignments to the current trip while they fit, and
//when the next consignment does not fit, close the current trip and start a new one with it. A single
//consignment never exceeds 240 bags.
//Read consignment sizes one at a time until a 0 is entered. Print the number of trips and the
//number of bags on the last trip.
#include <stdio.h>
int main(void) {
    int consignment;
    int trips = 0;
    int bags_on_last_trip = 0;
    while (1) {
        if (scanf("%d", &consignment) != 1 || consignment < 0 || consignment > 240) {
            return 1;
        }
        if (consignment == 0) {     
            break;
        }
        if (bags_on_last_trip + consignment > 240) {
            trips++;
            bags_on_last_trip = consignment;
        } else {
            bags_on_last_trip += consignment;
        }
    }
    if (bags_on_last_trip > 0) {
        trips++;
    }
    printf("Trips: %d\n", trips);
    printf("Bags on last trip: %d\n", bags_on_last_trip);
    return 0;
}           