#include<stdio.h> 
void main()
{
	int a[10],i,min=0,max=0;
	float sum;
	while(scanf("%d",&a[0])!=EOF )
	{
		sum=0.0;
		for(i=1;i<10;i++)
		{
			scanf("%d",&a[i]);
		}

		for(i=1;i<10;i++)
		{
			if(a[max]<a[i])
				max=i;
			if(a[min]>a[i])
				min=i;

		}
		a[min]=0;
		a[max]=0;
		for(i=0;i<10;i++)
 	    {
			sum+=a[i];
        }
		sum/=8;
		printf("%.2f",sum);
	}
}