#include<stdio.h>
int tohop (int n, int k){
	if ((k==0) || (k==n))
	{
		return 1;
	}
	else {
		return tohop(n-1,k) + tohop(n-1,k-1);
	}
}
main () {
	int n,k;
	printf("nhap n va k:");
	scanf("%d%d",&n,&k);
	printf("to hop cua %dC%d la: %d",n,k,tohop(n,k));
}