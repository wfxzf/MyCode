#include <stdio.h>
#include <stdlib.h>

int main()
{
  char c;
  scanf("%c",&c);
  if(c>='a'&&c<='z')
    printf("lower");
  else
    if(c>='A'&&c<='Z')
    printf("upper");
  else
    if(c>='0'&&c<='9')
    printf("digit");
  else
    printf("other");
    return 0;
}
