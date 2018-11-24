#include<stdio.h>
int main()
{
   int t;
   double n,m,sum,i=0;
   scanf("%d",&t);
   while(i<t)
   {   scanf("%lf %lf",&n,&m);
       sum=0;
       while(n<=m)
       {
           sum+=(1.0/(n*n));
           n++;
       }
       printf("%.5lf\n",sum);
       i++;
   }

    return 0;
}

