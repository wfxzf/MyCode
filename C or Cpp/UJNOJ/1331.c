#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,i,j,k,sum;
   while(scanf("%d",&n)!=EOF)
   {
       sum=0;
       for(i=10;i<=n;i++)
       {   k=0;
           for(j=2;j<i;j++)
           {
               if(i%j==0)
                k++;
           }
           if(k==0)
               sum+=i;
       }
       printf("%d\n",sum);
   }
    return 0;
}