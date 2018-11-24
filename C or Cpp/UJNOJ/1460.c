#include <stdio.h>
#include <math.h>
int main()
{
    double n;
    int x,i;
   while(scanf("%lf",&n)!=EOF)
   {
       i=0;
       while(n!=1)
       {   x=(int)n;
           if(x%2==0)
            {
                n=n/2;
                i++;
            }
           else
            {
                n=3*n+1;
                i++;
            }
       }
       printf("%d\n",i);

   }

    return 0;
}
