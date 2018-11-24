#include <stdio.h>
#include <math.h>
int main( )
{
double T,H,M,PI,R;
scanf("%lf",&T);
M=6*pow(10,24);
R=6.371*pow(10,6);
PI=4.0*atan(1.0);
H=pow((6.67*pow(10,(-11))*M*T*T)/(4*PI*PI),1.0/3.0)-R;
printf("%.0lf",H);
return 0;
}
