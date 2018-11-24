#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,i,a[100],x;
    while(scanf("%d",&t)!=-1)
    {
        while(t--)
       {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&x);
        for(i=0;i<n;i++)
            {
               if(a[i]%x==0)
                  printf("%d\n",a[i]);
               else if(a[i]%10==x||a[i]/10%10==x)
                  printf("%d\n",a[i]);
            }
       }
    }

    return 0;
}
