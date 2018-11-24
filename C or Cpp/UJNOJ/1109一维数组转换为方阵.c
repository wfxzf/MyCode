#include<stdio.h>
int main()
{
    int a[20],n,i,k,j,temp;
    while(scanf("%d",&n))
    {
      if(n==0)
      break;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
           {
            printf("%d ",a[j]);
           }
        printf("%d\n",a[j]);
        temp=a[n-1];
        for(;j>=0;j--)
         a[j+1]=a[j];
        a[0]=temp;
    }

    }
    return 0;
}
