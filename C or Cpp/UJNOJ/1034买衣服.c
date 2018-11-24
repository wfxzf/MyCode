#include<stdio.h>
int main()
{
    float n;
    scanf("%f",&n);
    if(n*95<300)
        printf("%.2f",n*95);
    else if(n*95>300)
        printf("%.2f",n*95*0.85);
    return 0;
}
