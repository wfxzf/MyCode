#include <stdio.h>
int main()
{
  int a,i=0,j=0,k=0;
  while(scanf("%d",&a)!=EOF)
  {
     if(a>0)
		 i++;
     else if(a<0&&a!=-32767)
	     j++;
     else if(a==0)
		 k++;
	 else if(a==-32767)
		 break;
  }
  printf("%d %d %d",i,j,k);
  return 0;
}