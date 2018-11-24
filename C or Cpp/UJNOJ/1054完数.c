#include<stdio.h>
int main()
{
	int i,j,m,sum=1;
	scanf("%d",&m);
	for(j=m;j>=6;j--)
	{
        sum=1;
		for(i=2;i<j;i++)
		{
			if(j%i==0)
				sum=sum+i;
		}
		if(sum==j)
			break;
	}
	printf("%d",sum);
}