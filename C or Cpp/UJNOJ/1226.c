#include<stdio.h>
#include<string.h>
char zhuan(char ch);
int main()
{
    char a;
    while(scanf("%c",&a)!=EOF)
    printf("%c",zhuan(a));
return 0;
}
char zhuan(char ch)
{
    if(ch<='9'&&ch>='0')
        ch=105-ch;
    return ch;
}