#include <stdio.h>
#include <stdlib.h>
double jiecheng(int n);
int main()
{
    double n,i;
    double sum=0;
    while(i)
    {
        if(scanf("%lf",&n)==-1)
            break;
            sum=0;
      for(i=1;i<=n;i++)
        sum+=jiecheng(i);
        printf("%lf\n",sum);
    }
    for(i=1;i<=n;i++)
        sum+=i;
    return 0;
}
double jiecheng(int n)
{
    double i;
    double ji=1;
    for(i=1;i<=n;i++)
        ji*=i;
    return ji;
}
