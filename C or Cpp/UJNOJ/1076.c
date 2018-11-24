#include<stdio.h>
int main()
{
    long a,n,i=0,x,ji=1;
    scanf("%ld",&n);
    while(i<n)
    {
        scanf("%ld",&a);
        ji=1;
        while(a>0)
        {
            x=a%10;
            a=a/10;
            ji*=x;
        }
        printf("%ld\n",ji);
        i++;
    }
    return 0;
}
