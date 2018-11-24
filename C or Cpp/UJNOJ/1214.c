#include<stdio.h>
#include<math.h>
double jisuan(double a,double b,double c);
int main()
{
   double x,y,z;
   while(scanf("%lf%lf%lf",&x,&y,&z)==3)
    printf("%.2lf\n",jisuan(x,y,z));
return 0;
}
double jisuan(double x,double y,double z)
{
    double res;
    res=(x+y)/(x-y)+(z+y)/(z-y*1.0);
    return res;
}
