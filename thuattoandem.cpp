#include<stdio.h>
int dem (int n,int k){
	if (n==0) {
		return k;
	}
	else {
		k++;
		return dem(n/10,k);
	}
}
main () {
	int n,k;
	printf("nhap n:");
	scanf("%d",&n);
	printf("so %d co %d chu so",n,dem(n,k));
}