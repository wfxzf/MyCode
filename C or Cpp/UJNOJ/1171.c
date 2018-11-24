#include "stdio.h"
void main()
{
	int a[5],n;
	while((scanf("%d",&n)!=EOF)&&(n!=0)) 
	{ 
		for(int i=1;i<=n;i++)
		{
			if(i<4)
			{			
				a[4]=a[i]=i;
			}
			else
			{
				a[4]=a[1]+a[3];
				a[1]=a[2];
				a[2]=a[3];
				a[3]=a[4];
			}
		}
		printf("%d\n\n",a[4]);
	}
}
