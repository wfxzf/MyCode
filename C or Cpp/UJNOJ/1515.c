#include <stdio.h>
#include <math.h>
int main()
{
   int a,b,c;
   scanf("%d %d",&a,&b);
   c=abs(a-b);
   if(c%2==0)
    printf("Å¼Êý");
   else
   printf("ÆæÊý");
    return 0;
}
