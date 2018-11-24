#include<stdio.h>
double fac(int a);
void combine(int m,int n);
int main()
{
    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
      combine(m,n);
    }
    return 0;
}
void combine(int m,int n)
{
        double C;
         C=fac(m)/(fac(n)*fac(m-n));
         printf("%.0f\n",C);
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
