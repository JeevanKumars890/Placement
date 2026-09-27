#include<stdio.h>
int main(void){
    int units;
    double sanctionedKw,recordedKw,powerFactor;
    int raed=scanf("%d %lf %lf %lf",&units,&sanctionedKw,&recordedKw,&powerFactor);
    double energyCharge=units*6.40;
    double seventyFive=0.75*recordedKw;
    int useMd=(seventyFive>sanctionedKw);
    double billableDemand=useMd*seventyFive + (1-useMd)*sanctionedKw;
    double demandCharge=210*billableDemand;
    int pfAbove=(int)(powerFactor*100+.5);
    int stepAbove=(pfAbove-95) *(pfAbove>95);
    int stepBelow=(90-pfAbove)*(pfAbove<90);
    double incentive=energyCharge*0.005*stepAbove;
    double penalty=energyCharge*0.01*stepBelow;
    double adjustment=incentive-penalty;
    double netBill=energyCharge+demandCharge+adjustment;
    printf("%.2f\n",energyCharge);
    printf("%.2f\n",demandCharge);
    printf("%.2f\n",adjustment);
    printf("%.2f\n",netBill);
}