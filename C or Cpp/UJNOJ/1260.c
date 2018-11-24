#include <stdio.h>
#include <string.h>
int xiaobiao(int *a,int n);
int main()
{
    int a[100],i,n;
    while(scanf("%d",&n)!=-1)
    {
      for(i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }
      printf("%d\n",xiaobiao(a,n));
    }
    return 0;
}
int xiaobiao(int *a,int n)
{

    int i,max;
       max=a[0];
    for(i=0;i<n;i++)
        if(max<a[i])
        {
            max=a[i];
        }
return max;
}
