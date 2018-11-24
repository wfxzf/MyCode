#include<stdio.h>
int main()
{
 int a,i=0;
 while(scanf("%d",&a)!=EOF)
 {   i=0;
     while(a>0)
     {
         a=a/10;
         i++;
     }
     printf("%d\n",i);
 }

    return 0;
}
