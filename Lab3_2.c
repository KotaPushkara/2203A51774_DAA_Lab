#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct package {
    int tracking_number;
    char recipient_address[100];
    char delivery_method[50];
};

void sort_packages_descending(struct package *packages, int n) {
    struct package temp;
    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (packages[i].tracking_number < packages[j].tracking_number) {
                temp = packages[i];
                packages[i] = packages[j];
                packages[j] = temp;
            }
        }
    }
}

void sort_packages_ascending(struct package *package, int n) {
	int i,j;
    struct package temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (package[i].tracking_number > package[j].tracking_number) {
                temp = package[i];
                package[i] = package[j];
                package[j] = temp;
            }
        }
    }
}

int main() {
    int n,i,j,choice;
    printf("Enter the number of packages: ");
    scanf("%d", &n);
    struct package *packages = (struct package *)malloc(n * sizeof(struct package));

    for ( i = 0; i < n; i++) {
        printf("Enter details for package %d\n", i + 1);
        printf("Tracking Number: ");
        scanf("%d", &packages[i].tracking_number);
        printf("Recipient Address: ");
        scanf(" %[^\n]%*c", packages[i].recipient_address);  
        printf("Delivery Method: ");
        scanf(" %[^\n]%*c", packages[i].delivery_method);    // To read a full line with spaces
    }
    printf("Choose sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        sort_packages_ascending(packages, n);
    } else if (choice == 2) {
        sort_packages_descending(packages, n);
    } else {
        printf("Invalid choice\n");
        free(packages);
        return 1;
    }

    
    printf("\nSorted packages based on tracking numbers (Descending Order):\n");
    for (i = 0; i < n; i++) {
        printf("Package %d:\n", i + 1);
        printf("Tracking Number: %d\n", packages[i].tracking_number);
        printf("Recipient Address: %s\n", packages[i].recipient_address);
        printf("Delivery Method: %s\n", packages[i].delivery_method);
        printf("\n");
    }

    
    free(packages);

    return 0;
}

