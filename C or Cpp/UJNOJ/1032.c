#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b;
    scanf("%c",&a);
    b=a;
    if(a>='a'&&a<='z')
        b=a-32;
    if(a>='A'&&a<='Z')
        b+=32;
    printf("%c",b);
    return 0;
}
