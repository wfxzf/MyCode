#include <stdio.h>
#include <stdlib.h>
int sushu(int a);
int main()
{
    int a;
    while(1)
    {
        if(scanf("%d",&a)==EOF)
          break;
        if(sushu(a)==0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
int sushu(int a)
{
    int i;
    for(i=2;i<a;i++)
    {if(a%i==0)
     return 0;}

return 1;

}
