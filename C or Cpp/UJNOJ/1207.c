#include<stdio.h>
#include<math.h>
double jisuan(int n);
int main()
{
   int n;
   while(scanf("%d",&n)!=EOF)
    printf("%lf\n",jisuan(n));
   return 0;
}
double jisuan(int n)
{
    int i;
    double sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=(2*i-1)*(2*i+1)/((2*i)*(2*i*1.0));
    }
    return sum;
}
