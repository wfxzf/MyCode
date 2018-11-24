#include <stdio.h>
#include <string.h>
 double x,xw;
 int xt;
void Nums(double num);
int main()
{

    while(scanf("%lf",&x)!=EOF)
    {
        Nums(x);
        printf("%d %lf\n",xt,xw);
    }
    return 0;
}
void Nums(double num)
{
   xt=(int)x;
   xw=x-xt;
}
