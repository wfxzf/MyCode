#include <stdio.h>
#include <math.h>
int main()
{
   double r,h,s1,s2,s,pi;
   pi=4*atan(1);
   while(scanf("%lf %lf",&r,&h)!=EOF)
   {
       s1=pi*r*r;
       s2=2*pi*r*h;
       s=2*s1+s2;
       printf("Area = %.3lf\n",s);
   }

    return 0;
}
