#include<stdio.h>
int songuoc (int n,int a) {
if (n==0) {
	return a;
}	
else {
	a=a*10 +n%10;
	return songuoc(n/10,a);
}
}
main () {
	
	int n,a;
	printf ("nhap n: ");
	scanf("%d",&n);
	printf("so nguoc cua n la: %d",songuoc(n,a));
}