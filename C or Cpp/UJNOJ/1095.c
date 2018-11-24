#include<stdio.h>
int main()
{
  /*1i 1j 2i1 3i 5j 8i1 13i 21j 34
  每一个数是前两个数之和*/
   int i=1,j=1,k=2,i1,n;
   while(scanf("%d",&n)!=EOF)
	  { i=1,j=1,k=2;
   if(n==1||n==2)
   printf("1\n");
     
   else
		 while(1)
	 {
	   i1=i+j;
	   k++;
	   if(n==k)
       {
		   printf("%d\n",i1);
	       break;
	   }
       i=j+i1;
	   k++;
	   if(n==k)
       {
		   printf("%d\n",i);
	       break;
	   }
	   j=i1+i;
	   k++;
	  if(n==k)
       {
		   printf("%d\n",j);
	       break;
	   } 
	 }
   }
return 0;
}