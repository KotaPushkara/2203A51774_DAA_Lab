#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for product details
struct product {
    char product_name[100];
    char category[50];
    float price;
};
void sort_products_ascending(struct product *products, int n) {
	int i,j;
    struct product temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (products[i].price > products[j].price) {
                temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
}

void sort_products_descending(struct product *products, int n) {
    struct product temp;
    int i,j;
    for ( i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (products[i].price < products[j].price) {
                temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
}

int main() {
    int n,i, choice;
    printf("Enter the number of products: ");
    scanf("%d", &n);

    struct product *products = (struct product *)malloc(n * sizeof(struct product));

    for (i = 0; i < n; i++) {
        printf("Enter details for product %d\n", i + 1);
        printf("Product Name: ");
        scanf(" %[^\n]%*c", products[i].product_name); 
        printf("Category: ");
        scanf(" %[^\n]%*c", products[i].category);    
        printf("Price: ");
        scanf("%f", &products[i].price);
    }

    printf("Choose sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        sort_products_ascending(products, n);
    } else if (choice == 2) {
        sort_products_descending(products, n);
    } else {
        printf("Invalid choice\n");
        free(products);
        return 1;
    }

    printf("\nSorted products based on price:\n");
    for (i = 0; i < n; i++) {
        printf("Product %d:\n", i + 1);
        printf("Product Name: %s\n", products[i].product_name);
        printf("Category: %s\n", products[i].category);
        printf("Price: %.2f\n", products[i].price);
        printf("\n");
    }

    free(products);

    return 0;
}

