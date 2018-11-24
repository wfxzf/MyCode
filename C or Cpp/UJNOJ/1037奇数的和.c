#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,s;
    scanf("%d",&n);
    if(n%2==1)
    {
           s=(n*n-1)/4;
        printf("%d",s);
    }
    else
     {
         s=n*n/4;
        printf("%d",s);
     }
    return 0;
}
