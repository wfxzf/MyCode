#include <stdio.h>
 
int main() 
{
    int a;
    scanf("%d",&a);
    if(a<=100&&a>=90)
     printf("A");
    else if(a>=80&&a<=89)
    printf("B");
    else if(a>=70&&a<=79)
    printf("C");
    else if(a>=60&&a<=69)
    printf("D");
    else if(a>=0&&a<=59)
    printf("E");
    return 0;
}
