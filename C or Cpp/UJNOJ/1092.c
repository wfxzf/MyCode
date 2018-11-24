#include<stdio.h>
int main()
{
	int N,a[101],i;
	double sum;
	while(1)
	{
		scanf("%d",&N);
		if(N==0) break;
		a[0]=0;
		for(i=1;i<=N;i++)
		{
			scanf("%d",&a[i]);
		}
		for(sum=0,i=1;i<=N;i++)
		{
			if(a[i]>a[i-1]) sum+=(a[i]-a[i-1])*6+5;
			if(a[i]<a[i-1]) sum+=(a[i-1]-a[i])*4+5;
			if(a[i]==a[i-1]) sum+=5;
		}
		printf("%.0f\n",sum);
	}
	return 0;
} 