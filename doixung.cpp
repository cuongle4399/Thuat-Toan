#include<stdio.h>
void nhap (int a[], int &n){
	printf("nhap so phan tu cua mang: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);
	}
}
int doixung (int a[], int batdau, int ketthuc) {
	if (batdau>= ketthuc){
		return 1;
	}
	if (a[batdau] != a[ketthuc]){
			return 0; 
	}
	else {
		return doixung(a,batdau+1,ketthuc-1);
	}
}
main () 
{
	int batdau,ketthuc,a[100],n;
	nhap(a,n);
	batdau=0;
	ketthuc=n-1;
	if (doixung(a,batdau,ketthuc)==1) {
		printf("mang nay doi xung");
	}
	else {
		printf("khong doi xung");
	}
}
