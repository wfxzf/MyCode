#include<stdio.h>
int main()
{
    int m,i;
    scanf("%d",&m);
    for(i=2;i<m;i++)
        if(m%i==0)
          break;
    if(i==m)
        printf("Prime");
    else
    printf("Not prime");
    return 0;
}
