#include <stdio.h>
int main()
{
    double n,sum=0;
    scanf("%lf",&n);
    while(n>0)
    {
        sum+=1/(n*(n+1));
        n--;
    }
    printf("%lf",sum);
    return 0;
}


