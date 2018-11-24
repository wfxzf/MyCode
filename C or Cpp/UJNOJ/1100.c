#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[20],m,n,i,j,temp;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        for(i=0;i<m+n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<m+n;i++)
        {
            for(j=0;j<m+n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        for(i=0;i<m+n-1;i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[i]);
    }
    return 0;
}
