#include <stdio.h>
#include <string.h>
double jiecheng(int n);
int main()
{
    char a[100];
    int i,t,n;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(a);
        n=strlen(a);
        for(i=n-1;i>=0;i--)
            printf("%c",a[i]);
        printf("\n");

    }
    return 0;
}