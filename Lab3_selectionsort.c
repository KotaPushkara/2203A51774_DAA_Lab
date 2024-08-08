#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, i;

    printf("Enter number of orders: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter priority numbers of the orders:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printf("Sorted priority numbers:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

