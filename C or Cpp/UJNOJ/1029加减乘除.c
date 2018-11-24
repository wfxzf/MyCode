#include<stdio.h>
int main()
{
    int x,y;
    char a;
    scanf("%d%d %c",&x,&y,&a);
    switch(a)
    {   
    case '+' :
        printf("%d",x+y);
        break;
    case '-' :
        printf("%d",x-y);
        break;
    case '*' :
        printf("%d",x*y);
        break;
    case '/' :
        printf("%d",x/y);
        break;
    }
     
     
     
}
