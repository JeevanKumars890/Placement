//A water tank sensor reports a raw level and a raw temperature, and a calibration routine has to
//correct both in place.
//Write void calibrate(float *level, float *temp, float levelOffset, float
//tempOffset) which adds the two offsets to the two readings through the pointers. Write void
//resetToZero(float *level, float *temp) which sets both readings to zero.
//In main, read the raw level, the raw temperature and the two offsets. Print the raw pair, call the
//calibration routine and print the corrected pair, then call the reset routine and print the pair again.
#include <stdio.h>

void calibrate(float *level, float *temp, float levelOffset, float tempOffset) {
    *level += levelOffset;
    *temp += tempOffset;
}

void resetToZero(float *level, float *temp) {
    *level = 0.0;
    *temp = 0.0;
}

int main() {
    float rawLevel, rawTemp, levelOffset, tempOffset;

    printf("Enter the raw level: ");
    scanf("%f", &rawLevel);
    printf("Enter the raw temperature: ");
    scanf("%f", &rawTemp);
    printf("Enter the level offset: ");
    scanf("%f", &levelOffset);
    printf("Enter the temperature offset: ");
    scanf("%f", &tempOffset);

    printf("Raw pair: %.2f, %.2f\n", rawLevel, rawTemp);

    calibrate(&rawLevel, &rawTemp, levelOffset, tempOffset);
    printf("Corrected pair: %.2f, %.2f\n", rawLevel, rawTemp);

    resetToZero(&rawLevel, &rawTemp);
    printf("Reset pair: %.2f, %.2f\n", rawLevel, rawTemp);

    return 0;
}