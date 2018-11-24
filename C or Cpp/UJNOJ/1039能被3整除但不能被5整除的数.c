#include<stdio.h>
int main()
{
    int i,m,n;
    scanf("%d %d",&m,&n);
    for(i=m;i<=n;i++)
    {
        if(i%3==0&&i%5!=0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}