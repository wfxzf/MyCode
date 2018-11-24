#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int T,a[10],i=0,k=0,x,n;
    scanf("%d",&T);
    while(T>0)
    {   i=0;k=0;
        scanf("%d",&n);
        while(i<n)
        {
            scanf("%d",&a[i]);
            i++;
        }
        i--;
        scanf("%d",&x);
        while(i>0)
        {
            if(a[i]==x)
                k++;
            i--;
        }
        if(k==0)
            printf("no find!\n");
        else
            printf("find!\n");
        T--;
    }
    return 0;
}