#include <stdio.h>
#include <stdlib.h>
int hef(int m,int n);
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d",hef(m,n));
    return 0;
}

int hef(int m,int n)
{

    int i;
    for(i=m;i>0;i--)
        if(m%i==0&&n%i==0)
          return i;
}
