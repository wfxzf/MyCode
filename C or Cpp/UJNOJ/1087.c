#include<stdio.h>
int main()
{
   double a,b;
   int c;
   while(scanf("%lf%lf%d",&a,&b,&c),a!=0&&b!=0&&c!=0)
   {
     printf("%.*lf\n",c,a/b);
   }
    return 0;
}
