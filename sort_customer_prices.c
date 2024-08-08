#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book_store {
    char book_title[50];
    char author[20];
    char publication_date[20];
    float price;
};

void sort(struct book_store *b, int n) {
    struct book_store temp;
    int i, j;
    for (i=0; i<n-1;i++) {
        for (j=i+1; j<n;j++) {
            if (b[i].price > b[j].price) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

int main() {
    struct book_store *s;
    int n, i;

    printf("\nEnter number of books to be stored: ");
    scanf("%d", &n);
	s = (struct book_store *)malloc(n * sizeof(struct book_store));

    for (i = 0; i < n; i++) {
        printf("Enter book %d details\n", i + 1);
        printf("Title: ");
        scanf("%s", s[i].book_title);
        printf("Author: ");
        scanf("%s", s[i].author);
        printf("Publication Date (dd/mm/yy): ");
        scanf("%s", s[i].publication_date);
        printf("Price: ");
        scanf("%f", &s[i].price);
    }

    sort(s, n);

    printf("\nBooks sorted by price:\n");
    for (i = 0; i < n; i++) {
        printf("Book %d: %s, Author: %s, Publication Date: %s, Price: %.2f\n", 
            i + 1, s[i].book_title, s[i].author, s[i].publication_date, s[i].price);
    }
    free(s);

    return 0;
}

