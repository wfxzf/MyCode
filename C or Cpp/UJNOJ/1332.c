#include <stdio.h>
#include <stdlib.h>

int main()
{
   int t,a[100],n,j,i;
   double sum;
   scanf("%d",&t);
   while(t>0)
    {
        sum=0;j=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
           sum+=a[i];
        }
        for(i=0;i<n;i++)
        {
           if(a[i]>=sum/n)
            j++;
        }
        printf("%.2lf %d\n",sum/n,j);
        t--;
    }
    return 0;
}
