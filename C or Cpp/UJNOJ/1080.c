
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a,b,x,y,z,count=0;
    while(1)
    {
        scanf("%d%d",&a,&b);
        count=0;
        if(a==0&&b==0)
            break;
        for(i=a;i<=b;i++)
            {
                x=i%10;y=i%100/10;z=i%1000/100;
                if(x*x*x+y*y*y+z*z*z==i)
                    count++;
            }
            printf("%d\n",count);
    }
    return 0;
}