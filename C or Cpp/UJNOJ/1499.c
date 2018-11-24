#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],i,t,n,max,min;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);

        }
        max=min=a[0];
        for(i=0;i<n;i++)
        {
            if(max<a[i])
                max=a[i];
            if(min>a[i])
                min=a[i];

        }
        printf("%d %d\n",max,min);

    }
    return 0;
}