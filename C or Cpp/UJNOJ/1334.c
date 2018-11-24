#include <stdio.h>
#include <stdlib.h>

int main()
{
   int t,a[101],n,j,i,k,x;
   scanf("%d",&t);
   while(t>0)
    {   k=0;j=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&x);
        for(i=0;i<n;i++)
        {
            if(x==a[i])
                j++;
            if(x<a[i])
                k++;
        }
        if(j>=1)
            printf("Find ");
        if(j==0)
            printf("No find ");
        printf("%d\n",k);
        t--;

    }
    return 0;
}
