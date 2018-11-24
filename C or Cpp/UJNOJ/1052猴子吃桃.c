#include<stdio.h>
 int main()
{
    int count=1,i,n; 
    scanf("%d",&n);
    for(i=1;i<n;i++)
        count=(count+1)*2;
    printf("%d",count);
    return 0;
} 