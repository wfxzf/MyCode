#include<stdio.h>
int main()
{
 int x,a,b,c;
 while(scanf("%d %d %d",&a,&b,&c)!=EOF)
 {
    
        for(x=10;x<=100;x++)
        {
          if(x%3==a&&x%5==b&&x%7==c)
             break;
        }
        if(x==101)
          printf("No answer\n");
        else
          printf("%d\n",x);

 }

    return 0;
}
