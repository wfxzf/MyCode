#include <stdio.h>
int main()
{
    float a,b,c,x;
    scanf("%f %f %f",&a,&b,&c);
    x=1/(1/a+1/b+1/c);
    printf("%.2f",x);
    return 0;
}
