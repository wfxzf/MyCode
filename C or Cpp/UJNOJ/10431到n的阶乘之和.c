#include<stdio.h>
#include<math.h>
int main()
{
	double i=1,n,sum=0,j,x=1;
	scanf("%lf",&n);
	for(i=1;i<=n;i++)
	{ x=1;
	  for(j=1;j<=i;j++)
	  {
	    x=x*j;
	  }
	  sum+=x;
	}
    
	printf("%.0lf",sum);
	return 0;
}