#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000];
    int i,j, n;
    while(1)
    {
        gets(s);
        if(strcmp(s,"2013")==0)
           break;
        for(i=j=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ')
		{
		s[j++]=s[i];
		}
	}
	s[j]='\0';
        n=strlen(s);
        for(i=0;i<n;i++)
           if(s[i]!=s[n-i-1]&&s[i]!=s[n-i-1]+32&&s[i]!=s[n-i-1]-32)
               break;
        if(i==n)
            printf("YES\n");
        else
            printf("NO\n");
    }

  return 0;
}
