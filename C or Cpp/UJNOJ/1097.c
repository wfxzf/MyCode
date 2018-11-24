#include <stdio.h>
#include <stdlib.h>

int main()
{
    double sum;
    int T,a[30],i,h,n;
    scanf("%d",&T);
    while(T>0)
    {   i=0;sum=0;h=0;
        scanf("%d ",&n);
        while(i<n)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            i++;
        }
        printf("%.2lf ",sum/n);
        i--;
        while(i>=0)
        {
            if(a[i]>sum/n)
                h++;
                i--;
        }
        printf("%d\n",h);
        T--;
    }
    return 0;
}
