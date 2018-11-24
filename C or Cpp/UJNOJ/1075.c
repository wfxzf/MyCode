#include<stdio.h>
int main()
{
    char ch;
    while(scanf("%c",&ch)!=EOF)
    {
        if((ch<='z'&&ch>='a')||(ch<='Z'&&ch>='A'))
            printf("alpha\n");
        else if(ch<='9'&&ch>='0')
            printf("numeric\n");
        else
            printf("other\n");
            getchar();
    }
    return 0;
}