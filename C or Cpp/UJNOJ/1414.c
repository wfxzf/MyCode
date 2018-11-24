#include <stdio.h>
#include <stdlib.h>
void pan(char a);
int main()
{
    char a;
    a=getchar();
    pan(a);
    return 0;
}

void pan(char a)
{
    if(a<='9'&&a>='0')
        printf("yes");
    else
        printf("no");
}
