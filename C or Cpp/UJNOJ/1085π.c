#include<stdio.h>
#include<math.h>
int main()
{
    double pi4,i=1;
    int a=1;
    while(1/(2*i-1)>pow(10,-7))
    {
       if (a%2==1)
         pi4+=1/(2*i-1);
       else
       pi4-=1/(2*i-1);
       i++;
       a++;
    }	
printf("%.6lf",4*pi4);
}