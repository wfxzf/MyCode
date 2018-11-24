#include<stdio.h>
int main(void)
{
int m,n,sum,i;
while(scanf("%d%d",&m,&n)!=EOF){
	sum=0;
	if(m>n)
	{
		i=m;m=n;n=i;
	}
	for(i=m;i<=n;i++){
		if(i%3==0)
			sum+=i;
	}
	printf("%d\n",sum);
}
return 0;
}