#include <stdio.h>
 int main()
 {
   int a,b,c;
   printf("Enter the value for A, B & C");
   scanf("%d %d %d",&a,&b,&c);
   if(a>b&&a>c)
   printf("Greatest Number is %d"a);
   else if(b>c&&b>a)
   printf("Greatest Number is %d"b);
   else
   printf("Greatest Number is %d"c)
   return 0;
 }