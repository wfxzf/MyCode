#include<stdio.h>
int main()
{
	int i=0,a, b, N;
	scanf("%d",&N);
	while (i < N)
	{
		scanf ("%d %d",&a,&b);
		printf("%d\n",a+b);
		i++;
	}
	return 0;
}
