#include <stdio.h>
#include <stdlib.h>
int yue(int a,int b);
int bei(int a,int b);
int main()
{
    int a,b;
    while(1)
    {
        if(scanf("%d%d",&a,&b)==EOF)
          break;
          printf("%d %d\n",yue(a,b),bei(a,b));

    }
    return 0;
}

int yue(int a,int b)
{
    int i,temp;
    if(a>b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    for(i=b;i>0;i--)
        if(b%i==0&&a%i==0)
        {
           break;
        }
  return i;
}
int bei(int a,int b)
{
    int i,temp;
    if(a>b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    for(i=b;;i++)
        if(i%b==0&&i%a==0)
        {
           break;
        }
  return i;
}
