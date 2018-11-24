#include<stdio.h>
double fac(int a);
void biaoda(int k,int m,int n);
int main()
{
    int k,m,n;
    while(scanf("%d%d%d",&k,&m,&n)!=EOF)
    {
      biaoda(k,m,n);
    }
    return 0;
}
void biaoda(int k,int m,int n)
{
        double C;
         C=fac(k)/(fac(m)+fac(n));
         printf("%lf\n",C);
}
double fac(int a)
{
    int i;
    double s=1;
    for(i=a;i>=1;i--)
    {
        s=s*i;
    }
    return s;
}
