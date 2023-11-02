#include <stdio.h>

void selectionsort(int a[], int n);

void main() {
    int a[100];
    int n;
    int i;
    printf("\nRonit Satish Mehta 60009230207");
    printf("\nEnter the number of elements to be in an array: ");
    scanf("%d", &n);

    printf("\nStart entering the numbers of the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Before sorting:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", a[k]);
    }

    printf("\nIterations:\n");
    selectionsort(a, n);

    printf("\nAfter sorting:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", a[k]);
    }

}

void selectionsort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        int t = a[i];
        a[i] = a[min];
        a[min] = t;
        for (int k = 0; k < n; k++) {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
}
