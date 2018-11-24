#include <stdio.h>
#include <string.h>
int xiaobiao(int *a,int n);
int main()
{
    int a[100],i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",xiaobiao(a,n));
    return 0;
}
int xiaobiao(int *a,int n)
{

    int i,min,mini;
       min=a[0];
    for(i=0;i<n;i++)
        if(min>a[i])
        {
            min=a[i];
            mini=i;
        }
return mini;
}
