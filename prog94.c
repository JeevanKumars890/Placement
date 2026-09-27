#include <stdio.h>
#define NUM_MAX 5000
int addStrings(const char *num1, const char *num2, char *out);
int addStrings(const char *num1, const char *num2, char *out) {
  int len1 = 0;
  while (num1[len1] != '\0') {
    len1++;
  }
  int len2 = 0;
  while (num2[len2] != '\0') {
    len2++;
  }
  int i = len1 - 1;
  int j = len2 - 1;
  int carry = 0;
  int outLength = 0;
  while (i >= 0 || j >= 0 || carry > 0) {
    int digit1 = (i >= 0) ? (num1[i] - '0') : 0;

    int digit2 = (j >= 0) ? (num2[j] - '0') : 0;
    int sum = digit1 + digit2 + carry;
    carry = sum / 10;
    out[outLength] = (char)('0' + (sum % 10));
    outLength++;
    i--;
    j--;
  }
  if (outLength == 0) { /* both inputs were empty */
    out[outLength] = '0';
    outLength++;
  }
  out[outLength] = '\0'; /* step 5, the one people forget */
  /* Step 6: reverse in place. */
  for (int left = 0, right = outLength - 1; left < right; left++, right--) {
    char t = out[left];
    out[left] = out[right];
    out[right] = t;
  }
  return outLength;
}
int main(void) {
  char num1[NUM_MAX];
  char num2[NUM_MAX];
  if (scanf("%4999s", num1) != 1) {
    return 1;
  }
  if (scanf("%4999s", num2) != 1) {
    return 1;
  }
  char result[NUM_MAX + 2];
  addStrings(num1, num2, result);
  printf("%s\n", result);
  return 0;
}