#include<stdio.h>
int main()
{
int i,j,s,m;
scanf("%d",&m);
for(i=1;i<=m;i++)
{	
	s=1;
	for(j=2;j<=i/2;j++)
	if(i%j==0)s+=j;
	if(s==i)
                printf("%d\n",i);
}
return 0;
}