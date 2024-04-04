#include <stdio.h>

void nhap(int a[], int &n) {
    printf("nhap so phan tu n: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu thu %d: ", i);
        scanf("%d", &a[i]);
    }
}
int max(int a[],int n) {
	if (n==1) {
		return a[0];
	}
	else {
		int x=max(a,n-1);
		if (x>a[n-1]) {
			return x;
		}
		else {
			return a[n-1];
		}
	}
}

int main() {
    int a[100], n;
    nhap(a, n);
    printf("so lon nhat trong mang la: %d", max(a, n));
    
    return 0;
}