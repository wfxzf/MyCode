#include <stdio.h>
#include <string.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a>b)
        printf("%d %d",b,(a-b)/2);
    else if(b>a)
        printf("%d %d",a,(b-a)/2);
    else if(a==b)
        printf("%d 0",a);
    return 0;
}
