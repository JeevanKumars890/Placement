#include <stdio.h>
int main(void){
    double coconutg,rendittKg,SlikPriceperkg,wageCostperKg;

    int read=scanf("%lf %lf %lf %lf",&coconutg,&rendittKg,&SlikPriceperkg,&wageCostperKg);
    double rawSilkProduced = coconutg / rendittKg;
    double grossRevenue = rawSilkProduced * SlikPriceperkg;
    double totalWageCost = coconutg * wageCostperKg;
    double netMargin = grossRevenue - totalWageCost;
    printf("%.2f\n%.2f\n%.2f\n%.2f\n", rawSilkProduced, grossRevenue, totalWageCost, netMargin);
    return 0;
}