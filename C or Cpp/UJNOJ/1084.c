#include<stdio.h>
int main()
{
  double n,sum,i;
  while(scanf("%lf",&n)!=EOF)
  {    sum=0;
      if(n==0)
        break;
      for(i=1;i<=n;i++)
      {
          sum+=1.0/i;
      }
      printf("%.3lf\n",sum);
  }
    return 0;
}
