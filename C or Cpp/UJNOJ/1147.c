#include <stdio.h>
int main ()
{
    int a[100],n,x,i,j,pos;
        while(scanf("%d",&n)!=EOF)
        {
            for(i=0;i<n;i++)
                scanf("%d",&a[i]);
            scanf("%d",&x);
            if(x<a[n-1])
                a[n]=x;
            else
            {
                for(pos=0;pos<n;pos++)
                    if(a[pos]<x)
                        break;
                    for(j=n+1;j>pos;j--)
                        a[j]=a[j-1];
                    a[pos]=x;
            }
            for(i=0;i<n;i++)
                printf("%d ",a[i]);
            printf("%d",a[i]);
            printf("\n");
        }
    return 0;
}