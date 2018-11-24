#include<stdio.h>
int main()
{
      int n;
      double x=1;
      scanf("%d",&n);
      for (int i=0;i<n;i++)
      x*=2;
      printf("%.0lf",x);
return 0;
}