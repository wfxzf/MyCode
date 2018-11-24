#include<stdio.h>
void hehe(char *a);
int main()
{
    char s[1000];
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        hehe(s);
    }
return 0;
}
void hehe(char *s)
{
    char s1[1000]={'0'};
    int i,j=0;
     for(i=0;s[i];i++)
 {
     s1[j++]=s[i];
     if((i+1)%3==0&&i!=0)
        s1[j++]=' ';
 }
  s1[j]='\0';
      puts(s1);
}
