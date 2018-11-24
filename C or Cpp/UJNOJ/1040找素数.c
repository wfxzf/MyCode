#include<stdio.h>
#include<math.h>
int main()
{
int m,n,i,j,k,leap;
scanf("%d %d",&m,&n);
for(i=m;i<=n;i++)
{
k=(int)sqrt(i);
leap=1;
for(j=2;j<=k;j++)
if(i%j==0)
{
leap=0;break;
}
if(leap==1)
{
printf("%d ",i);
}
}
return 0;
}