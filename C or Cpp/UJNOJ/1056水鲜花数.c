#include<stdio.h>
int main()
{   
   int m,n,i,a,b,c,j=0;
   scanf("%d %d",&m,&n);
   i=m;
   while(i<=n)
   {
     a=i%10;
	 b=i/10%10;
	 c=i/100%10;
	 if(a*a*a+b*b*b+c*c*c==i)
	 {
		 printf("%d ",i);
	     j++;
	 }
	 i++;
   }
   if(j==0)
	   printf("No");
}
