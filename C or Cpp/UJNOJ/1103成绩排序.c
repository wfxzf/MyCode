# include <stdio.h>
#include<stdlib.h>
#include  <time.h>
int main ()
{
    int a[10],i,j,temp;
    while(scanf("%d",&a[0])!=EOF)
    {
    	for(i=1;i<10;i++)
    	{
    		scanf("%d",&a[i]);
		}
        for(i=0;i<10;i++)
    	{   
		    for(j=0;j<10-1-i;j++)
         	{
		    	if(a[j]>a[j+1])
    	    	{
    		    	temp=a[j];
    	    		a[j]=a[j+1];
    		    	a[j+1]=temp;
		    	}
	    	}
		}
		for(i=0;i<9;i++)
	     {
	     	printf("%d ",a[i]);
		 }
        printf("%d\n",a[i]);
	}
	    return 0;
	}