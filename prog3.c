#include<stdio.h>
int main(void){
    int depth;
    int read=scanf("%d",&depth);

    int slabFeet=depth*(depth<300) +300 *(depth>=300);
    int beyond300=depth-300;
    beyond300=(beyond300>0)*beyond300;
    int slab2Feet=beyond300*(beyond300<200) + 200*(beyond300>=200);
    int slab3Feet=(depth-500)*(depth>500);
    int  casingFeet=depth*(depth<60)+60*(depth>=60);
    int drillingcharge=75*slabFeet + 95*slab2Feet + 130*slab3Feet;
    int casingCharge=400*casingFeet;
    int total=drillingcharge+casingCharge;
    printf("Drilling Charge:$%d\nCasingCharge:$%d\nTotal:$%d", drillingcharge, casingCharge, total);
    return 0;
}