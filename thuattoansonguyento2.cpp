#include<stdio.h>
#include<math.h>
bool ktsonguyento (int n,int i){
	if (n<2) {
		return false;
	}
	if (i<2) {
		return true;
	}
	if (n%i==0) {
		return false;
	}
	else return ktsonguyento(n,i-1);
}
main () {
	int n;
	printf("nhap n:");
	scanf("%d",&n);
	int i=sqrt(n);
	if (ktsonguyento(n,i) == true) {
		printf("day la so nguyen to");
	}
	else 
	printf("day khong phai la so nguyen to");
}