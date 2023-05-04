#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE]; // input array
int subset[MAX_SIZE]; // temporary subset
int n; // size of input array
int target; // target sum

void backtrack(int idx, int sum, int len) {
    if (sum == target) { // target sum reached
        printf("{");
        for (int i = 0; i < len; i++) {
            printf("%d", subset[i]);
            if (i < len - 1) printf(", ");
        }
        printf("}\n");
        return;
    }
    if (idx == n || sum > target) { // end of input array or sum exceeded target
        return;
    }
    subset[len] = arr[idx]; // include current element
    backtrack(idx + 1, sum + arr[idx], len + 1);
    backtrack(idx + 1, sum, len); // exclude current element
}

int main() {
    printf("Enter the size of the input array: ");
    scanf("%d", &n);
    printf("Enter the input array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    printf("All subsets with sum equal to %d are:\n", target);
    backtrack(0, 0, 0);
    return 0;
}