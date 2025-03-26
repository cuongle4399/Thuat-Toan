#include<stdio.h>
int mu(int a,int b) {
	if (b==0) {
		return 1;
	}
	int k=mu(a,b/2);
	if (b%2==0) {
	    return k*k;
		 }
	else {
	    return k*k*a;
	}
}
main () {
	int a,b;
	printf("nhap a va b:");
	scanf("%d%d",&a,&b);
	printf("luy thua cua %d mu %d la: %d",a,b,mu(a,b));
}