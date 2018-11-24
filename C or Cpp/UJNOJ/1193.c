#include <stdio.h>
#include <string.h>
int SumNums(int num);
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        printf("%d\n",SumNums(x));
    }
    return 0;
}
int SumNums(int num)
{
 if (num<10)
 return num;
 int res = 0;
 res = (num%10)+SumNums(num/10);
 return res;
}
