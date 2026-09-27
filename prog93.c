#include <stdio.h>
#define LINE_MAX 512
#define FIELD_MAX 128
#define FIELD_COUNT 5
int main(void) {
  char line[LINE_MAX];
  if (fgets(line, sizeof(line), stdin) == NULL) {
    return 1;
  }
  int length = 0;
  while (line[length] != '\0') {
    length++;
  }
  if (length > 0 && line[length - 1] == '\n') {
    length--;
    line[length] = '\0';
  }
  char field[FIELD_COUNT][FIELD_MAX];
  int fieldLength[FIELD_COUNT] = {0};
  int fieldIndex = 0;
  int writePos = 0;
  int tooManyFields = 0;
  for (int i = 0; i < length; i++) {
    if (line[i] == '|') {
      if (fieldIndex < FIELD_COUNT) {
        field[fieldIndex][writePos] = '\0';
        fieldLength[fieldIndex] = writePos;
      }
      fieldIndex++;
      writePos = 0;
      if (fieldIndex >= FIELD_COUNT) {
        tooManyFields = 1;
      }
    } else if (fieldIndex < FIELD_COUNT && writePos < FIELD_MAX - 1) {
      field[fieldIndex][writePos] = line[i];
      writePos++;
    }
  }
  if (fieldIndex < FIELD_COUNT) {
    field[fieldIndex][writePos] = '\0';
    fieldLength[fieldIndex] = writePos;
  }
  if (tooManyFields || fieldIndex != FIELD_COUNT - 1) {
    printf("ERROR: FIELD COUNT\n");
    return 0;
  }
  /* Quantity by ASCII arithmetic, no atoi. */
  long quantity = 0;
  if (fieldLength[2] == 0) {
    printf("ERROR: INVALID QUANTITY\n");
    return 0;
  }
  for (int i = 0; i < fieldLength[2]; i++) {
    char c = field[2][i];
    if (c < '0' || c > '9') {
      printf("ERROR: INVALID QUANTITY\n");
      return 0;
    }
    quantity = quantity * 10 + (c - '0');
  }
  if (quantity == 0) {
    printf("ERROR: INVALID QUANTITY\n");
    return 0;
  }
  if (fieldLength[3] != 4) {
    printf("ERROR: PAPER CODE\n");
    return 0;
  }
  int isCmyk = (fieldLength[4] == 4 && field[4][0] == 'C' &&
                field[4][1] == 'M' && field[4][2] == 'Y' && field[4][3] == 'K');
  int isMono = (fieldLength[4] == 4 && field[4][0] == 'M' &&
                field[4][1] == 'O' && field[4][2] == 'N' && field[4][3] == 'O');
  if (!isCmyk && !isMono) {
    printf("ERROR: COLOUR\n");
    return 0;
  }
  printf("Job: %s\n", field[0]);
  printf("Customer: %s\n", field[1]);
  printf("Quantity: %ld\n", quantity);
  printf("Paper: %s\n", field[3]);
  printf("Colour: %s\n", field[4]);
  return 0;
}