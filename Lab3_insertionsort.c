#include <stdio.h>

void insertionSort(int arr[], int n) {
    int key, k;
    for (k = 1; k < n; k++) {
        key = arr[k];
        int m = k - 1;
        while (m >= 0 && arr[m] > key) {
            arr[m + 1] = arr[m];
            m = m - 1;
        }
        arr[m + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter number of products: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter product IDs:\n");
    for (n = 0; n < sizeof(arr) / sizeof(arr[0]); n++) {
        scanf("%d", &arr[n]);
    }

    insertionSort(arr, sizeof(arr) / sizeof(arr[0]));

    printf("Sorted product IDs:\n");
    for (n = 0; n < sizeof(arr) / sizeof(arr[0]); n++) {
        printf("%d\n", arr[n]);
    }

    return 0;
}

