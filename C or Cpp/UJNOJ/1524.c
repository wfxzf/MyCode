#include<stdio.h>
int main()
{
    int n,x,i,j=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x%2==0)
            j++;
    }
    printf("%d",j);

   return 0;
}
