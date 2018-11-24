#include <stdio.h>
#include <stdlib.h>

int main()
{
   int m,n,sum=0;
   scanf("%d %d",&m,&n);
   for(;m<=n;m++)
   {
       if(m%3==0&&m%5==0)
       {
           sum+=m;
       }
   }
   printf("%d",sum);
    return 0;
}
