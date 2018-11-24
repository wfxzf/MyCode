#include<stdio.h>
int main()
{
	int a[10001],i,m,n,L,M,s,t;
	scanf("%d",&t);
	while(t--)
    {
        scanf("%d%d",&L,&M);
	for(i=0;i<=L;i++)
	{
		a[i]=1;
	}
	while(M--)
	{
		scanf("%d%d",&m,&n);
		for(i=m;i<=n;i++)
		{
			a[i]=0;
		}
	}
	for(s=0,i=0;i<=L;i++)
	{
		s=s+a[i];
	}
	printf("%d\n",s);
    }

	return 0;
}
