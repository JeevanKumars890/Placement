//A vehicle registration is entered inconsistently, with mixed case and stray spaces, for example as
//a line reading two spaces then ka 09 mh 1234 then two spaces.
//Read one line. Report the character count before cleaning and the character count after cleaning,
//where cleaning means removing every space and converting to upper case. If the cleaned plate is
//exactly 10 characters, print it in the canonical grouped form, two characters, a hyphen, two
//characters, a hyphen, two characters, a hyphen, four characters. Otherwise print INVALID PLATE.
//The counts are reported in every case, including invalid ones.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char plate[100];
    printf("Enter vehicle registration: ");
    fgets(plate, sizeof(plate), stdin);
    int originalCount = strlen(plate);
    // Remove newline character if present
    if (plate[originalCount - 1] == '\n') {
        plate[originalCount - 1] = '\0';
        originalCount--;
    }
    char cleaned[100];
    int cleanedCount = 0;
    for (int i = 0; plate[i] != '\0'; i++) {
        if (!isspace((unsigned char)plate[i])) {
            cleaned[cleanedCount++] = toupper((unsigned char)plate[i]);
        }
    }
    cleaned[cleanedCount] = '\0'; // Null-terminate the cleaned string
    printf("Original character count: %d\n", originalCount);
    printf("Cleaned character count: %d\n", cleanedCount);
    if (cleanedCount == 10) {
        printf("Canonical form: %.2s-%.2s-%.2s-%.4s\n", cleaned, cleaned + 2, cleaned + 4, cleaned + 6);
    } else {
        printf("INVALID PLATE\n");
    }
    return 0;
}   