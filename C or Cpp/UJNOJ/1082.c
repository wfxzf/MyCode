#include<stdio.h>
int main()
{
 int x,a,b;
    scanf("%d %d",&a,&b);
    //x=1500-si;
    //a<=si<=b
    //1500-b<=x<=1500-a
    for(x=1500-b;x<=1500-a;x++)
        if(x%3==2&&x%5==4&&x%7==6)
        printf("%d\n",x);
    return 0;
}
