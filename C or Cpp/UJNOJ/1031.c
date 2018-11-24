#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    double d,e,f,x1,x2,y,z;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a==0)
        printf("No\n");
    else
    {  
        d=b*b-4*a*c;
        if(d>=0)
        {
            d=sqrt(d);
            e=-b-d;//ะก
            f=-b+d;//ด๓
            x1=e/(2*a);
            x2=f/(2*a);
                printf("%.2lf %.2lf\n",x1,x2);
        }
        else
        {
            d=-d;
            d=sqrt(d);
            z=-b/(2*a);
            y=d/(2*a);
            printf("%.2lf-%.2lfi %.2lf+%.2lfi\n",z,y,z,y);
        }
    }
    return (0);
}