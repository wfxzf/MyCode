#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j;
    char a[200],b[100];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
          gets(a);
          gets(b);
          for(i=0,j=strlen(a);b[i]!='\0';i++,j++)
               {
                a[j]=b[i];
               }
               a[j]='\0';
               puts(a);
    }

	return 0;
}
