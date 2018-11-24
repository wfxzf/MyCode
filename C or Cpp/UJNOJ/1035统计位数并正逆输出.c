#include <stdio.h>
int main()
{
    int x,n=0,i=0,a[5];
    scanf("%d",&x);
    while(x>0)
    {
        a[i]=x%10;
        x/=10;
        i++;
    }
    printf("%d\n",i);
    n=i-1;
    while(n>0)
    {
        printf("%d ",a[n]);
        n--;
    }
    printf("%d\n",a[n]);
    while(n<i-1)
    {
        printf("%d ",a[n]);
        n++;
    }
    printf("%d",a[n]);
    return 0;
}