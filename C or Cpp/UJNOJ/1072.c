#include <stdio.h>
#include <stdlib.h>

int main()
{
    float c,f;
    while(1)
    {
        scanf("%f",&f);
        if(f==0) break;
        c=5.0/9*(f-32);
        printf("%.2f\n",c);
    }
    return 0;
}
