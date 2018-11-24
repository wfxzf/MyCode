#include <stdio.h>
#include <stdlib.h>

int main()
{
   int j,i,n,sum=0,cheng;
    while(scanf("%d",&n)!=EOF)
    {   sum=0;
        for(i=n;i>0;i=i-2)
        {
            cheng=1;
            for(j=i;j>0;j--)
            {
             cheng*=j;
            }
            sum+=cheng;
        }
    printf("%d\n",sum);
    }
    return 0;
}
