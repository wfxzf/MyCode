#include<stdio.h>
int main()
{
 int a,b,c;
 while(scanf("%d %d %d",&a,&b,&c)!=EOF)
 {
     if(a==0&&b==0&&c==0)
        break;
     if(a+b>c&&a+c>b&&b+c>a)
     {
         if(a*a+b*b==c*c||b*b+c*c==a*a||a*a+c*c==b*b)
            printf("yes\n");
         else
            printf("no\n");
     }
     else
        printf("not a triangle\n");
 }
    return 0;
}
