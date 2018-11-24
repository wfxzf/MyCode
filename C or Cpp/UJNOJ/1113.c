#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,n;
    int a[10][10];
    while(1)
    {   k=0;
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
              scanf("%d",&a[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i][j]!=a[j][i])
                k++;
        if(k==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
