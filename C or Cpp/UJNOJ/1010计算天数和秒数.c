#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,today,days,hour,minute,second;
    scanf("%d",&n);
    today=n%(3600*24);
    days=n/(24*3600);
    hour=today/3600;
    minute=today%3600/60;
    second=today%3600%60;
    printf("%02d %02d:%02d:%02d",days,hour,minute,second);
    return 0;
}