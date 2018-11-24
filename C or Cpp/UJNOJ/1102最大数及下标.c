# include <stdio.h>
#include<stdlib.h>
#include  <time.h>
int main ()
{
    int a[20],i,n,m,mi;
    while(scanf("%d",&n)!=EOF)
    {
    	if(n==0)
    	break;
    	scanf("%d",&a[0]);
    	m=a[0];
    	for(i=1;i<n;i++)
    	{
    		scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(m<a[i])
			{
				m=a[i];
				mi=i;
			}
		}
		printf("%d %d\n",m,mi);
	}
	    return 0;
	}