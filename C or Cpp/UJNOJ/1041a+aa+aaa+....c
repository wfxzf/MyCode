#include<stdio.h>
#include<math.h>
int main()
{
	double a,i=1,n,sum=0,x=0;
	scanf("%lf %lf",&a,&n);
    for(i=1;i<=n;i++)
	{
		x=x+a*pow(10,i-1);
	    sum=sum+x;
	}
	printf("%.0lf",sum);
	return 0;
}
