//A lender produces the repayment schedule for a loan.
//Write double emiAmount(double principal, double annualRatePercent, int months)
//returning the equated monthly instalment.
//Write void printSchedule(double principal, double annualRatePercent, int months)
//which prints, for each month, the opening balance, the interest component, the principal
//component and the closing balance, and then the total interest paid over the whole tenure.
//Write int monthsToHalfPrincipal(double principal, double annualRatePercent, int
//months) returning the month number in which the outstanding balance first drops below half the
//original principal, or 0 if it never does within the tenure.
//In main, read the principal, the annual interest rate percentage and the tenure in months, and run
//all three.
//The EMI formula is given. Do not derive it.
//r = annualRatePercent / 12 / 100
//EMI = P * r / (1 - pow(1 + r, -n))
//Each month, the interest component is the opening balance times the monthly rate, the principal
//component is the instalment less that interest, and the closing balance is the opening balance less
//the principal component. The final instalment settles whatever balance remains, so the schedule
//closes at exactly zero
#include <stdio.h>
#include <math.h>

double emiAmount(double principal, double annualRatePercent, int months) {
    double r = annualRatePercent / 12 / 100;
    return principal * r / (1 - pow(1 + r, -months));
}

void printSchedule(double principal, double annualRatePercent, int months) {
    double emi = emiAmount(principal, annualRatePercent, months);
    double balance = principal;
    double totalInterest = 0;

    printf("Month\tOpening Balance\tInterest\tPrincipal\tClosing Balance\n");
    for (int i = 1; i <= months; i++) {
        double interest = balance * (annualRatePercent / 12 / 100);
        double principalComponent = emi - interest;
        balance -= principalComponent;
        totalInterest += interest;
        printf("%d\t%.2f\t\t%.2f\t%.2f\t%.2f\n", i, balance + principalComponent, interest, principalComponent, balance);
    }
    printf("Total Interest Paid: %.2f\n", totalInterest);
}

int monthsToHalfPrincipal(double principal, double annualRatePercent, int months) {
    double emi = emiAmount(principal, annualRatePercent, months);
    double balance = principal;
    for (int i = 1; i <= months; i++) {
        double interest = balance * (annualRatePercent / 12 / 100);
        double principalComponent = emi - interest;
        balance -= principalComponent;
        if (balance < principal / 2) {
            return i;
        }
    }
    return 0;
}

int main() {
    double principal, annualRatePercent;
    int months;
    printf("Enter principal amount: ");
    scanf("%lf", &principal);
    printf("Enter annual interest rate percentage: ");
    scanf("%lf", &annualRatePercent);
    printf("Enter tenure in months: ");
    scanf("%d", &months);

    printSchedule(principal, annualRatePercent, months);
    printf("Month when outstanding balance drops below half the original: %d\n", monthsToHalfPrincipal(principal, annualRatePercent, months));

    return 0;
}