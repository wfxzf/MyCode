#include <stdio.h>
  int main()
{
  int a;
  scanf("%d",&a);
    if(a%15==0)
    printf("该数能同时被3和5整除");
    else if((a%3)==0&&(a%5)!=0)
    printf("该数能被其中一个数整除");
    else if((a%5)==0&&(a%3)!=0)
    printf("该数能被其中一个数整除");
    else
    printf("该数既不能被3整除也不能被5整除");
   return 0;
}
 