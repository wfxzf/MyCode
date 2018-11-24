#include <stdio.h>
#include <string.h>
int main()
{
   char a[200];
   int t,i;
   scanf("%d",&t);
   getchar();
while(t--)
{
    gets(a);
    for(i=0;a[i]!='\0';i++)
        if(a[i]<='z'&&a[i]>='a')
        a[i]-=32;
    puts(a);
    for(i=0;a[i]!='\0';i++)
    if(a[i]<='Z'&&a[i]>='A')
      a[i]+=32;
    puts(a);
}
  return 0;
}
