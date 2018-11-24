#include<stdio.h>
int he(int a);
int main()
{
    int a;
    while(scanf("%d",&a)!=-1)
    printf("%d\n",he(a));
return 0;
}
int he(int a)
{
    int b,k=0,sum;
    if(a%10%2==0)
    {sum=a%10;
        a/=10;}
    while(a>0)
    {
        b=a%10;
        if(b%2==0)
            {
                sum=sum*10;
                sum+=b;
                k++;
            }
            a/=10;
    }
    if(k!=0)
        return sum;
    return 0;
}
