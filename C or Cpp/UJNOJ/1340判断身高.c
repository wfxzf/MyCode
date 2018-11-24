#include <stdio.h>
  int main()
{
  int a;
  scanf("%d",&a);
  if(a<=155&&a>=0)
    printf("low");
  if(a>=156&&a<=175)
    printf("moderate");
  if(a>=176)
    printf("high");
 
   return 0;
}
 