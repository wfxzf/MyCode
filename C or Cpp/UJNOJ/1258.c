#include <stdio.h>
int digui(int n);
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",digui(n)+18);
    }
    return 0;
}
int digui(int n)
{
     if(1 == n) {
            return 0;
     }else {
            return digui(n-1)-2;
     }

}