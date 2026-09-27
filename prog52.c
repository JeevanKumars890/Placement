//A farmer is choosing between three irrigation pumps for filling one tank.
//Write int minutesToFill(float tankLitres, float flowLpm) returning the whole number of
//minutes needed to fill the tank, rounding up.
//Write float energyUnits(int minutes, float pumpKw) returning the units of electricity
//consumed, which is the running time in hours multiplied by the pump rating.
//Write float costOfCycle(float tankLitres, float flowLpm, float pumpKw, float
//tariff) which calls both of the above and returns the cost of one fill cycle.
//In main, read the tank capacity and the tariff, then read three pump options each given as a flow
//rate in litres per minute and a rating in kW. Print a line for each pump and then the cheapest
//option
#include <stdio.h>
#include <math.h>

int minutesToFill(float tankLitres, float flowLpm) {
    float minutes = tankLitres / flowLpm;
    return (int)ceil(minutes);
}

float energyUnits(int minutes, float pumpKw) {
    float hours = minutes / 60.0;
    return hours * pumpKw;
}

float costOfCycle(float tankLitres, float flowLpm, float pumpKw, float tariff) {
    int minutes = minutesToFill(tankLitres, flowLpm);
    float energy = energyUnits(minutes, pumpKw);
    return energy * tariff;
}

int main() {
    float tankCapacity, tariff;
    printf("Enter tank capacity (litres): ");
    scanf("%f", &tankCapacity);
    printf("Enter electricity tariff ($/kWh): ");
    scanf("%f", &tariff);

    for (int i = 1; i <= 3; i++) {
        float flowRate, pumpRating;
        printf("Enter flow rate (litres/minute) and rating (kW) for pump %d: ", i);
        scanf("%f %f", &flowRate, &pumpRating);

        float cost = costOfCycle(tankCapacity, flowRate, pumpRating, tariff);
        printf("Pump %d: $%.2f\n", i, cost);
    }

    return 0;
}