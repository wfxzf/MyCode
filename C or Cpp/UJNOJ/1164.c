#include<stdio.h>
void fac(int n);
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
      fac(n);
    }
    return 0;
}
void fac(int n)
{
   double ji=1,i;
   for(i=1;i<=n;i++)
        ji*=i;
   printf("%.0lf\n",ji);
}
