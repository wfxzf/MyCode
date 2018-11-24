#include<stdio.h>
int main()
{   int m,n,i,x;
	scanf("%d %d",&m,&n);
	if(m<=n)
		i=n;
	else
		if(m>n)
			i=m;
	while(1)
	{
	  if(n%i==0&&m%i==0)
	  {
		  printf("%d ",i);
	     break;
	  }
	  i--;
	}
	if(m<=n)
		i=n;
	else
		if(m>n)
			i=m;
	while(1)
	{
	  if(i%n==0&&i%m==0)
	  { 
		  printf("%d",i);
		  break;
	  }
	  i++;
	}
}