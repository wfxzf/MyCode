#include <stdio.h>
int main()
{
    int n,i,j,k,a[101],sum=0;
    scanf("%d%d%d",&n,&i,&j);
    for(k=1;k<=n;k++)
        scanf("%d",&a[k]);
    for(k=i;k<=j;k++)
        sum+=a[k];
    printf("%d",sum);
    return 0;
}

