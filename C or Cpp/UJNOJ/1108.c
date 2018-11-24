#include<stdio.h>
double zh(int a,int b);
double jc(int a);
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
    {
        //for(j=0;j<=n-i-2;j++)
            //printf(" ");
        for(j=0;j<i;j++)
            printf("%.0lf ",zh(i,j));
        printf("%.0lf\n",zh(i,j));
    }
    }

return 0;
}
double jc(int a)
{
    int i;
    double ji=1;
    for(i=a;i>0;i--)
    {
        ji*=i;
    }
    return ji;
}
double zh(int a,int b)
{
    double pls;
    pls=jc(a)/(jc(a-b)*jc(b));
    return pls;
}
