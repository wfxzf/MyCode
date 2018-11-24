#include <stdio.h>
#include <stdlib.h>
int gwsh(int m);
int main()
{
    int m;
    while(scanf("%d",&m)!=-1)
    {
        printf("%d\n",gwsh(m));
    }
    return 0;
}
int gwsh(int m)
{
    int sum=0;
    for(;m>0;)
    {
        sum+=m%10;
        m/=10;
    }

    return sum;
}
