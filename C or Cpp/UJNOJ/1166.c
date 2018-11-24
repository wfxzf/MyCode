#include <stdio.h>
#include <stdlib.h>
void type(char a);
int main()
{
    char a;
    while(scanf("%c%*c",&a)!=EOF)
    {
        type(a);
    }
  return 0;
}
void type(char a)
{
    if(a>='0'&&a<='9')
        printf("Digit\n");
    else
        printf("Other\n");
}
