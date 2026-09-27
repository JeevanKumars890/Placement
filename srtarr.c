// execute a binary search program in c on a sorted array
// int array = {10, 20, 30, 40, 50};
#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, target, result;

    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d sorted numbers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &target);

    result = binarySearch(arr, n, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}