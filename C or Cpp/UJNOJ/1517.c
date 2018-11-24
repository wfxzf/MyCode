#include<stdio.h>
int main()
{
    int a[100],t,n,i;
    float sum;
    scanf("%d",&t);
    while(t>0)
    {   sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        printf("%.2f\n",sum/n);
        t--;
    }

   return 0;
}
