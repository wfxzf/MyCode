#include<stdio.h>
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for (i=0;i<n;i++)
        {
            for(j=0;j<2*n;j++)
            {   if(j<i)
                printf(" ");
                else if(j>=i&&j<2*n-1-i)
                printf("#");
            }
            printf("\n");
        }
    }

}

