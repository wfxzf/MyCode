#include <stdio.h>
#include <stdlib.h>

int main()
{
   double j,i,n,cheng;
   scanf("%lf",&i);
    while(i>0)
    {
        scanf("%lf",&n);
        cheng=1;
        for(j=n;j>0;j--)
        {
           cheng*=j;
        }
    printf("%.0lf\n",cheng);
    i--;
    }
    return 0;
}
