#include <stdio.h>
  int main()
{
  int a;
  scanf("%d",&a);
  if(a<=5)
    printf("cold");
  if(a>5&&a<26)
    printf("warm");
  if(a>=26)
    printf("hot");
 
   return 0;
}