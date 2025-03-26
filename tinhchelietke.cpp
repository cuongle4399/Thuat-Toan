#include<stdio.h>
void nhap(int a[], int &n){
	printf("nhap so phan tu cua mang n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		printf("a[%d]",i);
		scanf("%d",&a[i]);
	}
}
void lietke(int a[],int n) {
	for(int i=0;i<n;i++) {
		int k=0;
		for(int j=i+1;j<n;j++) {
			if (a[i]== a[j]) {
				k++;
		}
		if (k==0) {
		printf("%d ",a[i]);
		}
	}
}
main (){
	int a[100];int n;
	nhap(a,n);
	lietke(a,n);
	
}