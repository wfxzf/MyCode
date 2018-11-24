#include <stdio.h>
#include <stdlib.h>

int main()
{
   int t,n,i,j,a[100],temp;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       for(i=0;i<n;i++)
          scanf("%d",&a[i]);
       for(i=0;i<n-1;i++)
          for(j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
              {
                 temp=a[j];
                 a[j]=a[j+1];
                 a[j+1]=temp;
              }
        for(i=0;i<n-1;i++)
           printf("%d ",a[i]);
        printf("%d\n",a[i]);


    }
return 0;
}
