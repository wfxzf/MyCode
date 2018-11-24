/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d",&a);
    while(a>0)
    {
        b=a%10;
        printf("%d ",b);
        a/=10;
    }
    return 0;
}
*/



#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d",&a);
    while(a>10)
    {
        b=a%10;
        printf("%d ",b);
        a/=10;
    }
    printf("%d",a%10);
    return 0;
}