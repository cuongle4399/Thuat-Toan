#include<stdio.h>
int ucln (int a,int b)
{
	if (b==0) {
		return a;
	}
	else {
		return ucln (b,a%b);
	}
}
main () {
	int a,b;
	printf("nhap a: ");
	scanf("%d",&a);
	printf("nhap b: ");
	scanf("%d",&b);
	printf("UCLN cua a va b la: %d",ucln (a,b));
}