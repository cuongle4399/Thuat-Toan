#include<stdio.h>
void nhap(int a[], int &n){
	printf("nhap so phan tu cua mang n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		printf("a[%d]",i);
		scanf("%d",&a[i]);
	}
}
int sohoanthien (int a[], int n, int x){
	int s=0;
	for(int j=1;j<x;j++){
		if (x%j==0) {
			s=s+j;
		}
	}
	if (x==s) {
		return 1;
	}
	else {
		return 0;
	}
}
main (){
	int a[100];int n;
	int max=6,k=0;
	nhap(a,n);
	for(int i=0;i<n;i++) {
	if (sohoanthien (a,n,a[i]) == 1) {
		k++;
		if (a[i]>= max) {
			max=a[i];
		}
	}
	}
	if (k>0) {
		printf("%d la so hoan thien lon nhat \n ",max);
	}
	else {
		printf("khong co so hoan thien nao trong mang");
	}
}