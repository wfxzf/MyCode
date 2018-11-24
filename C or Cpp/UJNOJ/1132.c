#include <stdio.h>
#include <string.h>

int main()
{
    char a[200],b[200];
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(a);
        gets(b);
        strcat(a,b);
        puts(a);
    }
    return 0;
}
