#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int year=0,n;
    double x=1.0;
    scanf("%d",&n);
    while(x<pow(2,n))
       {
        x=x*(1+0.075);
        year++;
       }
       printf("%d",year);
    return 0;
}
