#include <stdio.h>
#include <stdlib.h>
double f(int n);
int main()
 {
 	int n;
	 while(scanf("%d",&n)!=EOF)
	 {
	 	printf("%lf\n",f(n)+1);
	  } 
	return 0;
}
double f(int n)
{
	double sum=0;
	int i;
	for(i=n;i>0;i-=2)
      {
      	sum+=1.0/i;
	  }
	return sum;
}