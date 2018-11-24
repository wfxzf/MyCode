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
    	for(i=0;i<n;i++)
    	{
    		scanf("%d",&a[i]);
		}
        for(i=n-1;i>0;i--)
    	{
    		printf("%d ",a[i]);
		}
		printf("%d\n",a[i]);
	}
	    return 0;
	}