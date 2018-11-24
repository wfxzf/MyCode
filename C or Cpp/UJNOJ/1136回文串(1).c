#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    int i, n;
    while(gets(s)!=NULL)
    {
        n=strlen(s);

        for(i=0;i<n;i++)
           if(s[i]!=s[n-i-1]&&s[i]!=s[n-i-1]+32&&s[i]!=s[n-i-1]-32)
               break;
        if(i==n)
            printf("Yes\n");
        else
            printf("No\n");
    }

  return 0;
}
