#include<stdio.h>
int luythua(int a,int b)
{
   if (b==0) {
       return 1;
}
   int x= luythua(a,b/2);
   if (b%2==0)
      return x*x;
   else
       return a*x*x;
}
main () {
printf("nhap a va b: ");
int a,b;
scanf("%d%d",&a,&b);
printf("luy thua cua %d mu %d la: %d",a,b,luythua(a,b));
}