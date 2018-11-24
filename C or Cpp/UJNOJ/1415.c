#include <stdio.h>
#include <stdlib.h>
int wan(int a);
int main()
{
    int a;
    scanf("%d",&a);
    if(wan(a)==1)
        printf("yes");
    else
        printf("no");
    return 0;
}

int wan(int a)
{

    int i,sum=0;
    for(i=1;i<a;i++)
        {
            if(a%i==0)
                {sum+=i;}
        }
    if(sum==a)
        return 1;

return 0;
}
