#include <stdio.h>

int main()
{
  int a[100],t,n,i,j,temp,count;
  scanf("%d",&t);
  while(t--)
  {
      count=0;
      scanf("%d",&n);
      for(i=0;i<n;i++)
        scanf("%d",&a[i]);
      for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
          if(a[i]>a[j])
         {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            count++;
         }
     printf("%d",count);
  }
  return 0;
}