#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a,b,shang,yushu;
   float a1,b1,zhi;
   scanf("%d %d",&a,&b);
   shang = a / b;
   yushu = a % b;
   a1 = a;
   b1 = b;
   zhi = a1 / b1;
   printf("%d %d %.2f",shang,yushu,zhi);
   return 0;
}
