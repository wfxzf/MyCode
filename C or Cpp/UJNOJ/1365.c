#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],n,i,sum=0,count=0;
    double ave;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {scanf("%d",&a[i]);sum+=a[i];}
    ave=sum*1.0/n;
    for(i=0;i<n;i++)
        if(a[i]<=ave)
        count++;
    printf("%.2lf %d",ave,count);

    return 0;
}
