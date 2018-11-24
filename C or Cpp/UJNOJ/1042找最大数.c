#include <stdio.h>
int main()
{
    int x,m;
    scanf("%d",&x);
    m=x;
    while(1)
    {
         scanf("%d",&x);
        if (x==0)
        break;
        if (x>m)
        m=x;
    }
printf("%d\n",m);
return 0;
}