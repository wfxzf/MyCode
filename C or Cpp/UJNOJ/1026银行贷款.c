#include<stdio.h> 
int main() 
{ 
   int n; 
   double a; 
   scanf("%lf %d",&a,&n); 
   if(n<=12) 
   {for(;n>0;n--) 
   {a+=0.009*a; 
   } 
   } 
    else if(n<=24&&n>12) 
   {for(;n>0;n--) 
   {a+=0.01*a; 
   } 
   } 
    else if(n>24&&n<=36) 
   {for(;n>0;n--) 
   {a+=0.0111*a; 
   } 
   } 
    else if(n>=36) 
   {for(;n>0;n--) 
   {a+=0.012*a; 
   } 
   } 
   printf("%.2lf",a); 
   return 0; 
  
  
  
} 
