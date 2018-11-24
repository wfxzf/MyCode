#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i,j,k,t,n,temp,a[100];
   scanf("%d",&t);
   for(;t>0;t--)
   {
   	k=0;
   	scanf("%d",&n);
   	for(i=0;i<n;i++)
   	{
   		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			k++;
		    }
		}
	}
	printf("%d\n",k);
   	
   }
	return 0;
}