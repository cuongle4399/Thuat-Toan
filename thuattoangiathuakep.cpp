#include<stdio.h> 
int giathuakep(int n){
if (n==1 || n==0) {
	return 1;
}
else {
	return n*giathuakep(n-2);
}
}
main () {
	int n;
	printf("nhap n:");
	scanf("%d",&n);
	printf("gia thua kep cua %d la: %d",n,giathuakep(n));
}