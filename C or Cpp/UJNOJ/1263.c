#include <stdio.h>
#include <string.h>
void paixu(int *a,int n);
int main()
{
    int a[100],i,n;
    while(scanf("%d",&n)!=-1)
    {
      for(i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }
      paixu(a,n);
      for(i=0;i<n-1;i++)
      {
          printf("%d ",a[i]);
      }
      printf("%d\n",a[i]);

    }
    return 0;
}
void paixu(int *a,int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
        for(j=0;j<n-1-i;j++)
          if(a[j]>a[j+1])
    {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
    }
}
