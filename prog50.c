//A fertiliser dealer computes the quantity and the number of whole bags required for each of a
//farmer's plots.
//Write double doseForPlot(double areaHa, double ratePerHa) returning the total quantity of
//fertiliser required for a plot, which is the area multiplied by the rate per hectare.
//Write double bagsNeeded(double quantityKg, double bagSizeKg) returning the number of
//whole bags required, rounding up. A part bag counts as a whole bag, because bags are not split.
//In main, read three plots, each given as an area, a rate per hectare and a bag size, and print the
//dose and the bag count for each.
#include <stdio.h>
#include <math.h>
double doseForPlot(double areaHa, double ratePerHa) {
    return areaHa * ratePerHa;
}
double bagsNeeded(double quantityKg, double bagSizeKg) {
    return ceil(quantityKg / bagSizeKg);
}
int main(void) {
    for (int i = 0; i < 3; i++) 
     {
        double areaHa, ratePerHa, bagSizeKg;
        if (scanf("%lf %lf %lf", &areaHa, &ratePerHa    , &bagSizeKg) != 3 || areaHa < 0 || ratePerHa < 0 || bagSizeKg <= 0) {
            return 1;
     }
        double dose = doseForPlot(areaHa, ratePerHa);
        double bags = bagsNeeded(dose, bagSizeKg);
        printf("Dose: %.2f kg, Bags needed: %.0f\n", dose, bags);
    }
    return 0;
}