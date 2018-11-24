#include<stdio.h>
int main()
{
    int a[10][10],b[10][10],m,n,i,j;
    while(scanf("%d%d",&m,&n))
    {     if(m==0&&n==0)
          break;

            for(i=0;i<m;i++)
            {
               for(j=0;j<n;j++)
               {
                scanf("%d",&a[i][j]);
               }
            }
            for(i=0;i<m;i++)
            {
               for(j=0;j<n;j++)
               {
                 scanf("%d",&b[i][j]);
               }
            }
            for(i=0;i<m;i++)
            {
                for(j=0;j<n-1;j++)
               {
                printf("%d ",a[i][j]+b[i][j]);
               }
            printf("%d\n",a[i][j]+b[i][j]);
           }

    }
    return 0;
}
