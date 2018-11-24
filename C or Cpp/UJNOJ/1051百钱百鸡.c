#include<stdio.h>
int main()
{
 int a,b,c;
 for(a=0;a<20;a++)
    for(b=0;b<(100-5*a)/3;b++)
    {  c=100-a-b;                
       if(c%3==0 && a*5+b*3+c/3==100)        
          printf("%d %d %d",a,b,c);
      }
 return 0;
}
