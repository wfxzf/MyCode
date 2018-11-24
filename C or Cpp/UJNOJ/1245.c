#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,j;
   for(i=1;i<=(11+1)/2;i++)
    {
        for(j=1;j<=(11+1)/2-i;j++)
            printf(" ");
        for(j=1;j<=2*i-1;j++)
            printf("*");
        printf("\n");
    }
   for(i=i-2;i>=0;i--)
    {
        for(j=1;j<=(11+1)/2-i;j++)
            printf(" ");
        for(j=1;j<=2*i-1;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}