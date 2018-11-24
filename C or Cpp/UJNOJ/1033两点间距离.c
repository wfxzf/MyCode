#include <stdio.h>
#include <math.h>

int main( )

{
    double x1,y1,x2,y2,temp,d;
    scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    temp=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    d=sqrt(temp);
    printf("%.2lf",d);
    return 0;
     }
