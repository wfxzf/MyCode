#include <stdio.h>
#include <stdlib.h>
double mn(int m,int n);
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=-1)
    {
        printf("%.0lf\n",mn(m,n));
    }
    return 0;
}
double mn(int m,int n)
{
    int i;
    double mi=1;
    for(i=0;i<n;i++)
    {
        mi*=m;
    }
    return mi;
}