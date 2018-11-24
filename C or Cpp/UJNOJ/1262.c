#include <stdio.h>
#include <string.h>
double xiaobiao(int *a,int n);
int main()
{
    int a[100],i,n;
    while(scanf("%d",&n)!=-1)
    {
      for(i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }
      printf("%.4lf\n",xiaobiao(a,n));
    }
    return 0;
}
double xiaobiao(int *a,int n)
{

    int i;
    double ave,sum;
    for(i=0;i<n;i++)
           sum+=a[i];
    ave=sum/(n*1.0);
return ave;
}
