#include <stdio.h>
#include <stdlib.h>
int wan(int a);
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",wan(a));
    return 0;
}

int wan(int a)
{

    int i,sum=1;
    for(i=1;i<a;i++)
        {
            sum+=1;
            sum*=2;
        }

return sum;
}
