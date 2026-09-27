//A distribution utility checks the health of its transformers and issues a report line for each.
//Write float loadPercent(float loadKva, float ratedKva) returning the load as a
//percentage of the rated capacity.
//Write char healthCode(float pct) returning the character 'N' for normal when the load is
//below 80 percent, 'W' for warning when it is from 80 up to and including 100 percent, and 'O' for
//overloaded when it is above 100 percent.
//Write int isActionNeeded(char code) returning 1 when the code is 'W' or 'O', and 0 otherwise.
//Write void printReport(int transformerId, float loadKva, float ratedKva) which
//calls all three and prints one formatted report line.
//In main, read four transformers and call the report function for each.
#include <stdio.h>
float loadPercent(float loadKva, float ratedKva) {
    return (loadKva / ratedKva) * 100.0f;
}
char healthCode(float pct) {
    if (pct < 80.0f) {
        return 'N';
    } else if (pct <= 100.0f) {
        return 'W';
    } else {
        return 'O';
    }
}
int isActionNeeded(char code) {
    return (code == 'W' || code == 'O');
}
void printReport(int transformerId, float loadKva, float ratedKva) {
    float pct = loadPercent(loadKva, ratedKva);
    char code = healthCode(pct);
    int actionNeeded = isActionNeeded(code);
    printf("Transformer %d: Load %% = %.2f, Health Code = %c, Action Needed = %s\n", transformerId, pct, code, actionNeeded ? "Yes" : "No");
}
int main(void){
    for(int i=0; i<4; i++){
        int transformerId;
        float loadKva, ratedKva;
        if(scanf("%d %f %f", &transformerId, &loadKva, &ratedKva) != 3){
            return 1; // Error reading input
        }
        printReport(transformerId, loadKva, ratedKva);
    }
    return 0;
}