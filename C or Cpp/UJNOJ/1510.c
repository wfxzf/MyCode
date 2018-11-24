#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n%3==0&&n%7==0)
        printf("Yes");
    else
        printf("No");
    return 0;
}