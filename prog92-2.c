//A student attendance record is a string in which A means absent, L means late and P means
//present. A student is eligible for an award if they were absent fewer than 2 days in total and were
//never late on 3 or more consecutive days.
//Read the record and print true when the student is eligible and false otherwise.
#include <stdio.h>
#include <string.h>

int main() {
    char record[100];
    printf("Enter attendance record: ");
    fgets(record, sizeof(record), stdin);

    size_t len = strlen(record);
    if (len > 0 && record[len - 1] == '\n') {
        record[len - 1] = '\0';
    }

    int absences = 0;
    int consecutiveLates = 0;
    int eligible = 1; // Assume eligible until proven otherwise

    for (int i = 0; record[i] != '\0'; i++) {
        if (record[i] == 'A') {
            absences++;
            consecutiveLates = 0; // An absent day breaks a late streak
            if (absences >= 2) {
                eligible = 0; // Fewer than 2 absences are required
                break;
            }
        } else if (record[i] == 'L') {
            consecutiveLates++;
            if (consecutiveLates >= 3) {
                eligible = 0; // 3 or more consecutive lates
                break;
            }
        } else if (record[i] == 'P') {
            consecutiveLates = 0; // Reset consecutive lates on present
        }
    }

    printf("%s\n", eligible ? "true" : "false");
    return 0;
}