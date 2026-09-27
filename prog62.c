//A mandi posts a price board for one commodity at the end of each week. Read the seven daily
//prices and report the highest price with the day it occurred, the lowest price with its day, the
//weekly average, and the number of days on which the price was above the average. Days are
//numbered from 1.
#include <stdio.h>

int main() {
    float prices[7];
    float sum = 0, average, highest, lowest;
    int highest_day, lowest_day;
    int above_average = 0;

    // Read the seven daily prices
    for (int i = 0; i < 7; i++) {
        printf("Enter the price for day %d: ", i + 1);
        scanf("%f", &prices[i]);
        sum += prices[i];
    }

    // Calculate the weekly average
    average = sum / 7;

    // Initialize highest and lowest with the first price
    highest = prices[0];
    lowest = prices[0];
    highest_day = 1;
    lowest_day = 1;

    // Find the highest and lowest prices and their respective days
    for (int i = 1; i < 7; i++) {
        if (prices[i] > highest) {
            highest = prices[i];
            highest_day = i + 1;
        }
        if (prices[i] < lowest) {
            lowest = prices[i];
            lowest_day = i + 1;
        }
    }

    // Count the number of days the price was above the average
    for (int i = 0; i < 7; i++) {
        if (prices[i] > average) {
            above_average++;
        }
    }

    // Display the results
    printf("Highest price: %.2f (Day %d)\n", highest, highest_day);
    printf("Lowest price: %.2f (Day %d)\n", lowest, lowest_day);
    printf("Weekly average: %.2f\n", average);
    printf("Number of days above average: %d\n", above_average);

    return 0;
}