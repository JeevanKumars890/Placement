//Given an integer array sorted in non-decreasing order, remove the duplicates in place so that each
//unique element appears exactly once, keeping the original relative order, and return the number of
//unique elements. The first k elements of the array must hold those unique values.
//Read n, then the n integers. Print k, then the first k elements of the array on the next line.
#include <stdio.h>

int removeDuplicates(int *nums, int n) {
    if (n == 0) return 0;
    int k = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int nums[100]; // Assuming maximum 100 elements
    printf("Enter the elements in non-decreasing order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int k = removeDuplicates(nums, n);
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}