#include <stdio.h>
#include <math.h>
int main( )
{
   int x,a,b,c;
   scanf("%d",&x);
   a=x%3;
   b=x%5;
   c=x%7;
   if(a==0&&b==0&&c==0)
    printf("Yes");
   else
    printf("No");
}
 