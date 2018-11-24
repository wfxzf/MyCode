#include <stdio.h>
#include <stdlib.h>
double jiecheng(int n);
int main()
{
    char a[100];
    int count=0;
    int i=0;
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if((a[i]<='z'&&a[i]>='a')||(a[i]<='Z'&&a[i]>='A'))
           count++;

    }
    printf("%d",count);
    return 0;
}

