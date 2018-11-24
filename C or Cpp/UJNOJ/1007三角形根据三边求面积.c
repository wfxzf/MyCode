#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   float a,b,c,s,S,guodu;
   scanf("%f %f %f",&a,&b,&c);

   if(a + b > c && a + c > b && b + c > a)
   {s = (a + b + c)/2;
   guodu = s * (s - a) *(s - b) * (s - c);
   S = sqrt(guodu);
   printf("%.2f",S);}
   else
    printf("No");


   return 0;
}
