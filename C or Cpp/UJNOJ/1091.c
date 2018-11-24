#include <stdio.h>

int main()
{
    int i;
    double a[12],s=0;
    for(i=0;i<12;i++)
       {
        scanf("%lf",&a[i]);
        s+=a[i];
        }
     printf("$%.2lf",s/12);
     
     return 0;
}
