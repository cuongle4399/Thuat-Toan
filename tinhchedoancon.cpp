#include<stdio.h>
void nhap(int a[], int &n){
	printf("nhap so phan tu cua mang n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		printf("a[%d]",i);
		scanf("%d",&a[i]);
	}
}
void nhap1(int b[], int &m){
	printf("nhap so phan tu cua mang m:");
	scanf("%d",&m);
	for(int j=0;j<m;j++) {
		printf("b[%d]",j);
		scanf("%d",&b[j]);
	}
}
int ktra(int a[],int n, int b[], int m) {
	int c=0,k=0;
	for(int i=0;i<n;i++) {
		int u=0;
		for(int j=k;j<m;j++) {
			if (u==0) {
			if (a[i]== b[j]) {
				c++;
				k=j+1;u++;
			
			}
		}
		}
	}
	if (c==n) {
		return 1;
	}
	else {
		return 0;
	}
}
main () {
	int a[100],n,m,b[100];
	nhap(a,n);
	nhap1(b,m);
	if (ktra(a,n,b,m)==1) {
		printf("mang a la con cua mang b");
	}
	else {
		printf("mang a khong phai la con cua mang b");
	}
}