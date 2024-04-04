#include <stdio.h>

void sapXep(int a[], int n) {
    int i, j, k, tmp;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[k])
                k = j;
        tmp = a[i];	
        a[i] = a[k];
        a[k] = tmp;
    }
}

int main() {
    int a[] = {8, 1, 3, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);

    sapXep(a, n);

    printf("Mang da sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}